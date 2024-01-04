typedef enum {false, true} bool;

bool valIP(char *cadena) //xxx.xxx.xxx.xxx
{
	char *s=NULL, *p=NULL;
	int i=0;

	if(strlen(cadena)!=15)
	{
		return false;
	}
	else
	{
		for( i=0; i<12 ; i=i+4)
		{
			s=&(cadena[i]);
			p=strtok(s,".");
			
			//~ if(srlen(p))
		}
		
		
	}
	
	
	
	
}
