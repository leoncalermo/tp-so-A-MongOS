/*
 * i-mongo-store.c
 *
 *  Created on: 7 may. 2021
 *      Author: utnso
 */


#include "i_mongo_store.h"

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
  return log_create("i_mongo_store.log","i_mongo_store", 1, LOG_LEVEL_INFO);
}
