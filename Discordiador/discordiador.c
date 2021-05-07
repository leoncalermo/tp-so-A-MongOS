/*
 * discordiador.c
 *
 *  Created on: 7 may. 2021
 *      Author: utnso
 */


#include "discordiador.h"

int main(void){
	char* ip;
	char* puerto_mi_ram;
	char* puerto_i_mongo_store;
	int conexion_mi_ram;
	int conexion_i_mongo_store;



	t_log* logger;
	t_config* config;

	logger = iniciar_logger();
	log_info(logger,"soy un log");

	config = config_create("discordiador.config");

	//leer_consola(logger);

	//asignar valor de config a la variable valor
	ip = config_get_string_value(config, "IP");
	puerto_mi_ram = config_get_string_value(config, "PUERTO_MI_RAM");

	puerto_i_mongo_store= config_get_string_value(config, "PUERTO_I_MONGO_STORE");


	log_info(logger, "DESEAS INICIAR CONEXION?");
	char* leido;
	leido = readline(">");
	if (strcmp(leido, "si") == 0 ){
		conexion_mi_ram = crear_conexion(ip, puerto_mi_ram);
		log_info(logger, "CONEXION CREADA CON MI RAM");
		conexion_i_mongo_store = crear_conexion(ip, puerto_i_mongo_store);
		log_info(logger, "CONEXION CREADA CON I MONGO STORE");

		//enviar CLAVE al servirdor
		//enviar_mensaje(valor, conexion);
		iniciar_conversacion(conexion_mi_ram, conexion_i_mongo_store, logger);
		liberar_conexion(conexion_mi_ram);
		liberar_conexion(conexion_i_mongo_store);
	}
	else if(strcmp(leido, "no") == 0 ){
		log_info(logger, "SALIENDO.");
	}


	config_destroy(config);
	log_destroy(logger);
	return EXIT_SUCCESS;
}

void iniciar_conversacion(int conexion_mi_ram, int conexion_mongo_store, t_log* logger)
{
	//Ahora toca lo divertido!
	log_info(logger, "CON QUIEN DESEAS HABLAR");
	char* leido;
	int continuar_conversacion = 1;
	leido = readline(">");
	if(strcmp(leido, "mongo store") == 0){
	  log_info(logger, "ESTAS POR HABLAR CON MONGO STORE");
	  continuar_conversacion = enviar_paquete_a_servidor(conexion_mongo_store, logger);
	}
	else if(strcmp(leido, "mi ram") == 0) {
	  log_info(logger, "ESTAS POR HABLAR CON MI RAM");
	  continuar_conversacion = enviar_paquete_a_servidor(conexion_mi_ram, logger);
	}
	else {
		log_info(logger, "NO HABLASTE CON NADIE, SALIENDO.");
		return;
	}

	if(continuar_conversacion == 0 ){
	  iniciar_conversacion(conexion_mi_ram, conexion_mongo_store, logger);
	}

}
int enviar_paquete_a_servidor(int conexion,  t_log* logger){
	char* leido;
	leido = readline(">");

	if(strcmp(leido, "") != 0){
		t_paquete* paquete1 = crear_paquete();
		int tamanio = strlen(leido) + 1;
		agregar_a_paquete(paquete1, leido, tamanio);
		enviar_paquete(paquete1, conexion);
		eliminar_paquete(paquete1);
		enviar_paquete_a_servidor(conexion, logger);
	}
	else{
		log_info(logger, "DE VUELTA AL LOBBY...");
	}
	return 0;
}


t_log* iniciar_logger(void)
{
  return log_create("discordiador.log","discordiador", 1, LOG_LEVEL_INFO);
}
