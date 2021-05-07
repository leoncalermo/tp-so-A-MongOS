/*
 * discordiador.c
 *
 *  Created on: 7 may. 2021
 *      Author: utnso
 */


#include "discordiador.h"

int main(void){
	t_log* logger;
	t_config* config;

	logger = iniciar_logger();
	log_info(logger,"soy un log");
	log_destroy(logger);



	return EXIT_SUCCESS;
}


t_log* iniciar_logger(void)
{
  return log_create("discordiador.log","discordiador", 1, LOG_LEVEL_INFO);
}
