#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe xmlparse.c */

int XmlParse(char *filenm, char *tag)
{
    char tagstart[100] = {0}; //First tag
    char tagend[100] = {0};//Second tag

    char readbuffer[100000];

    FILE *fd;
    if ((fd = fopen(filenm, "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until end of file is encountered
    fscanf(fd, "%[^\0]", readbuffer);
    fclose(fd);

    //check enter buffer
    if ( strlen(readbuffer) <= 0 )
    {
        return -1;
    }

    //Create first tag
    memset(tagstart, 0, sizeof(tagstart));
    strcpy(tagstart, "<");
    strcat(tagstart, tag);
    strcat(tagstart, ">");

    //Create second tag
    memset(tagend, 0, sizeof(tagend));
    strcpy(tagend, "</");
    strcat(tagend, tag);
    strcat(tagend, ">");

    int fndstrt = 0;
    int fndend = 0;
    int indexst = -1;
    int indexend = -1;
    int fndinc = 0;
    int strnglen = strlen(readbuffer);
    int tagstlen = strlen(tagstart);
    int tagenlen = strlen(tagend);
    for(int i=0; i<=(strnglen - tagenlen); i++)
    {
        // Match first tag word at current position
        fndstrt = 1;
        for(int j=0; j<tagstlen; j++)
        {
            //If word is not matched
            if(readbuffer[i + j] != tagstart[j])
            {
                fndstrt = 0;
                break;
            }
        }

        // If word have been fndstrt then store the current fndstrt indexst
        if(fndstrt == 1)
        {
		indexst = i;
		
		for(int k=(indexst+tagstlen); k<=(strnglen - tagenlen); k++)
		{
			// Match end tag word at current position
			fndend = 1;
			for(int l=0; l<tagenlen; l++)
			{
				//If word is not matched
				if(readbuffer[k + l] != tagend[l])
				{
					fndend = 0;
					break;
				}
			}
			
			// If word have been fndend then store the current fndend indexend
			if( (fndstrt == 1) && (fndend == 1) )
			{
				indexend = k;
				fndinc++;

				int tlen = ((indexend+tagenlen) - indexst) + 1;
				char tstr[tlen];
				memset(tstr, 0, tlen);

				for(int m = 0; m < tlen; m++)
					tstr[m] = readbuffer[indexst+m];
				tstr[tlen] = 0;
				printf(" Tag Found: %d : %s \n", fndinc, tstr);

				break;
			}
		}
	}
    }
    return -1;
} // End of XmlParse()

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
	    printf("Please specify the XML file, and tag name as an input.\n");
	    exit(0);
    }
    
    //tag name which value you want to access
    //char tag[] = "author";

    char fname[256] = {0};
    strcpy(fname, argv[1]);
    char tag[256] = {0};
    strcpy(tag, argv[2]);


    //Function to get tag value
    XmlParse(fname, tag);

    return 0;
}
