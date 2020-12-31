#include "Menu.h"
#include "fxlib.h"
#include <string.h>

#define S_W 21
#define S_H 8

#define uchar unsigned char
#define U(txt) ((uchar*)txt)

#define TXT_FOOT (uchar*)"+MINES+++++++++++++++"
#define TXT_HEAD (uchar*)"+++++++++++++++++++++"

void _drawBorder()
{
	/*int i;
	locate(1,1);
	Print(TXT_HEAD);
	for(i = 2; i < S_H; i++)
	{
		locate(1,i); Print(U("+"));
		locate(S_W,i); Print(U("+"));
	}
	locate(1,S_H);
	Print(TXT_FOOT);*/
	PopUpWin(5);
}

int ShowMenu(char canCanel, char* options)
{
	_drawBorder();
	ShowMenuNoBorder(canCanel, options);
}

int ShowMenuNoBorder(char canCancel, char* options)
{
	unsigned int key;
	char selOption = 0;
	char* entries[S_H-2];
	int inpLen;
	int i;
	int entryCount;
	char* txtCopy;
	int res;
	
	//Bdisp_AllClr_DDVRAM();
	inpLen = strlen(options);
	txtCopy = (char*)malloc(inpLen+1);
	strcpy(txtCopy, options);
	entries[0] = txtCopy;
	for(i = 0, entryCount = 1; i < inpLen; i++)
	{
		if(txtCopy[i] == '\n')
		{
			entries[entryCount++] = &txtCopy[i+1];
			txtCopy[i] = '\0';
		}
	}
	
	res = 0;
	while(1)
	{
		// Draw
		//_drawBorder();
		for(i = 0; i < entryCount; i++)
		{
			locate(3, i + 2);
			if(i == selOption) Print(U(">"));
			else Print(U(" "));
			Print((uchar*)entries[i]);
		}
		
		// Action
		GetKey(&key);
		if(key == KEY_CTRL_EXIT && canCancel)
		{
			res = -1;
			break;
		}
		if(key == KEY_CTRL_EXE || key == KEY_CTRL_ALPHA)
		{
			res = selOption;
			break;
		}
		switch(key)
		{
			case KEY_CTRL_DOWN:
			selOption++;
			if(selOption >= entryCount) selOption = 0;
			break;
			case KEY_CTRL_UP:
			selOption--;
			if(selOption < 0) selOption = entryCount - 1;
			break;
		}
	}
	
	free(txtCopy);
	return res;
}

int ShowText(char* text)
{
	int i;
	int line = 0;
	int col = 0;
	uchar tmptxt[1];
	unsigned int key;
	
	tmptxt[1] = 0;
	_drawBorder();
	for(i = 0; text[i] != 0; i++)
	{
		if(text[i] == '\n')
		{
			line++;
			col = 0;
		}
		else
		{
			tmptxt[0] = text[i];
			locate(3 + col,line + 2); Print(tmptxt);
			col++;
		}
	}
	
	while(1)
	{
		GetKey(&key);
		if(key == KEY_CTRL_EXE || key == KEY_CTRL_ALPHA)
			return 1;
		else if(key == KEY_CTRL_EXIT)
			return 0;
	}
}

uchar ReadInt(int *value, int digitNum, int column, int row)
{
	unsigned int key;
	uchar digit;
	char input[10];
	int i;
	uchar tmp[2];
	uchar result;

	tmp[1] = 0;
	digit = 0;

	while(1)
	{
		locate(column, row);
		for(i = 0; i < digitNum; i++)
		{
			if(i < digit)
				tmp[0] = input[i] + '0';
			else if(i == digit)
				tmp[0] = '_';
			else
				tmp[0] = ' ';
			
			Print(tmp);
		}
		GetKey(&key);

		if(key >= KEY_CHAR_0 && key <= KEY_CHAR_9)
		{
			if(digit < digitNum)
			{
				input[digit] = key - KEY_CHAR_0;
				digit++;
			}
		}
		else if(key == KEY_CTRL_DEL)
		{
			if(digit > 0)
				digit--;
		}
		else if(key == KEY_CTRL_EXE)
		{
			result = 1;
			break;
		}
		else if(key == KEY_CTRL_EXIT)
		{
			result = 0;
			break;
		}
	}

	if(!result) return 0;
	*value = 0;
	for(i = 0; i < digit; i++)
	{
		*value *= 10;
		*value += input[i];
	}
	return 1;
}