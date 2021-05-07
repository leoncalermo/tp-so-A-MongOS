/*
 * discordiador.h
 *
 *  Created on: 7 may. 2021
 *      Author: utnso
 */

#ifndef DISCORDIADOR_H_
#define DISCORDIADOR_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>
#include "utils.h"
t_log* iniciar_logger(void);
int enviar_paquete_a_servidor(int conexion,  t_log* logger);
void iniciar_conversacion(int conexion_mi_ram, int conexion_mongo_store, t_log* logger);



#endif /* DISCORDIADOR_H_ */
