void infData(){
	//Data
	struct tm agora_data= {0};
    time_t tempo_data;
    time(&tempo_data);
    agora_data = *localtime(&tempo_data);
	
}
