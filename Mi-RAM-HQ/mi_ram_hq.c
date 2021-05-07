/*
 * mi-ram-hq.c
 *
 *  Created on: 7 may. 2021
 *      Author: utnso
 */


#include "mi_ram_hq.h"

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
  return log_create("mi_ram_hq.log","mi_ram_hq", 1, LOG_LEVEL_INFO);
}
