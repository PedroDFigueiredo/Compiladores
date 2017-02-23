int main(){

int i = 0;


	do{
		i++;
		if(i==5)
			break;
		write(i);
		
	}while(i<10);

	for(int i = 0; i < 10; i++){
		if(i != 5)
			continue;

		write(i);
		
	}

	for (int j = 0; j < 2; j++) 
        for (int k = 0; k < 5; k++) {   
            if (k == 3) continue;
            write(j);
            write(k); 
        }



    while(i<10){
    	i++;


    	write(i);
    }

    


	
} 



