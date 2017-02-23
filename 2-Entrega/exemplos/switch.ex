int main(){
	int a=0;
	int b=2;


  


    switch(b) {
        case  1 :
            a++;
        
        case  2 :{
            a++;
        }

        case  3 :{
            a++;
            break;

        }
        default :
            a = 10;
    }

    write(a);


}



