#include <stdio.h>
#include <string.h>
char contents[1000];
int main()
{
	char filename[200];
	char *buffer;
	scanf("%s",filename);
	FILE* fp = fopen(filename,"r");

	char c = getc(fp);
	char *line;
	int flag=0;
	int newline=0;
	int size = 0;
	while(c!=EOF)
	{
	//	printf("%c\n",c);
		if(c=='/')
		{
			c = getc(fp);
		//	printf("Second Char %c\n",c);
			if(c=='/')
			{
				//line = fgets(line, sizeof(line), fp);
				while(c!='\n')
					c = getc(fp);
				c = getc(fp);
			}
			else
			{
				contents[size++] = ' ';
				contents[size++] = '/';
				contents[size++] = c;
				contents[size++] = ' ';
				c = getc(fp);
			}
		}
		while(c=='\n')
			c = getc(fp);
		if(c=='(' || c==')' || c=='+' || c=='-' || c=='*' || c=='=' || c==';' || c=='\'' || c=='\"' || c=='{' || c=='}'||c==',' || c=='>' || c=='<'||c=='%')
		{
			contents[size++] = ' ';
			contents[size++] = c;
			contents[size++] = ' ';
		}
		else if(c=='/')
			continue;
		else
		{
			if(c==' ')
			{
				c = getc(fp);
				contents[size++] = ' ';
				contents[size++] = c;
				contents[size++] = ' ';
				c = getc(fp);
			}
			contents[size++] = c;
		}
		c = getc(fp);
	}
	for (int i = 0; i < size-1; ++i)
	{
		printf("%c",contents[i]);
	}
	printf("\n");
}