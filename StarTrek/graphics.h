/*Manic Moscow's  graphics library!*/


void DrawAt(int x, int y, unsigned char What);
void DrawBox(int top, int left, int width, int height, int style);
void ClearScreen();
void DrawLine(int left, int top, int width,int orientation);
void SetColor(int color);
void AltEnter();
void SetConsoleCursor(int x, int y);
void ProgressBar(int left, int top, int width, float amount, float max);
void ScrollLog(char Message[]);
void SetConsoleSize(int x, int y);


int messagecount;

void SetConsoleSize(int x, int y)
{
	static HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    SMALL_RECT DisplayArea = {0, 0, 0, 0};

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	DisplayArea.Right = x;
	DisplayArea.Bottom = y;

	SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
}

void ScrollLog(char Message[])
{
    int counter;
    int messagelength;
	messagecount ++;

    messagelength = strlen(Message);
  //  printf("String length: %i", messagelength);

	SetConsoleCursor(5,31 + messagecount);
//	cout << setw(50) << " ";
	SetConsoleCursor(5,32 + messagecount);
//	cout << setw(50) << " ";
	SetConsoleCursor(5,30 + messagecount);







    for (counter = 0; counter < messagelength ; counter++)
    {


	if (strcmpi(Message, "SCOTTY:") >0)
	SetColor(5);

	if ((strcmpi(Message, "SULU:") > 0))
	SetColor(0);

	if (strcmpi(Message, "SPOCK:") > 0)
	SetColor(7);

	if (strcmpi(Message, "CHECKOV:")==0)
	SetColor(11);
        SetConsoleCursor(5 + counter,30);
        Sleep(10);
        printf("%c",Message[counter]);
        SetColor(14);
        printf("%c",Message[counter+1]);
        Sleep(10);
    }


	if ((messagecount >6))
		messagecount = 0;


}


/*
DUMB PROGRESS BOX
In the future this function should have increased functionality
*/
void ProgressBar(int left, int top, int width, float amount, float max)
{
int b; //loop counter
	float percent;
	float wdthprcnt; // percentage of the width bar that needs drawing

	percent = (amount / max) * 100;


    wdthprcnt = (width * percent) / 100;


	for(b=(left + 1);b < (left + width);b++)
				{

					DrawAt(b,top,(unsigned char) 176);

				}

		for(b=(left + 1);b < (left + wdthprcnt);b++)
				{

					DrawAt(b,top,(unsigned char) 219);

				}
}


void SetConsoleCursor(int x, int y)
{
	static HANDLE hOut;
    int First = 1;
    COORD Position;
    /*--------------------------------------*/
    if(First)
    {
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        First = 0;
    }
    /*-------------------------------------*/
    Position.X = x;
    Position.Y = y;
    /*--------------------------------------*/
    SetConsoleCursorPosition(hOut,Position);
}

void DrawAt(int x, int y, unsigned char What)
{
    static HANDLE hOut;
    int First = 1;
    COORD Position;
    /*--------------------------------------*/
    if(First)
    {
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        First = 0;
    }
    /*-------------------------------------*/
    Position.X = x;
    Position.Y = y;
    /*--------------------------------------*/
    SetConsoleCursorPosition(hOut,Position);
    putchar(What);

}

void DrawBox(int top, int left, int width, int height, int style)
{
	int a,b;

	width = width + left;

	if ((style == 0))
	{

	for(a=(left + 1);a < width;a++) // Draw top part of box
	{
		DrawAt(a,top,(unsigned char) 205);
	}
	for(a=(left+1);a < width;a++)//mirror for the botttom
	{
		DrawAt(a,(top+height),(unsigned char) 205);
	}

	for(b=(top + 1);b<(top + height);b++)//left virtical bar
	{
		DrawAt(left,b,(unsigned char) 186);
	}

	for(b=(top+1);b<(top + height);b++)//right virtual bar
	{
		DrawAt(width,b,(unsigned char) 186);
	}

	DrawAt(left,(top + height), (unsigned char) 200);//bottom right corner
	DrawAt(left,top, (unsigned char) 201);//top left corner
	DrawAt(width,top,(unsigned char) 187);
	DrawAt(width,(top + height),(unsigned char) 188);
	}
	else
	{
		for(a=(left + 1);a < width;a++) // Draw top part of box
			{
				DrawAt(a,top,(unsigned char) 196);
			}
		for(a=(left+1);a < width;a++)//mirror for the botttom
			{
			DrawAt(a,(top+height),(unsigned char) 196);
			}

		for(b=(top + 1);b<(top + height);b++)//left virtical bar
			{
			DrawAt(left,b,(unsigned char) 179);
			}

		for(b=(top+1);b<(top + height);b++)//right virtual bar
		{
		DrawAt(width,b,(unsigned char) 179);
		}

	DrawAt(left,(top + height), (unsigned char) 192);//bottom right corner
	DrawAt(left,top, (unsigned char) 218);//top left corner
	DrawAt(width,top,(unsigned char) 191);
	DrawAt(width,(top + height),(unsigned char) 217);
	}

}


void DrawLine(int left, int top, int width, int orientation)
{
		int a,b;

		switch(orientation)
			{
			case 1:
				for(a=(top + 1);a<(top + width);a++)//left virtical bar
				{
					DrawAt(left,a,(unsigned char) 186);
				}
				break;

			case 2:

				for(b=(left + 1);b < (left + width);b++) // Draw top part of box
				{

					DrawAt(b,top,(unsigned char) 205);

				}

				break;
			};

}

void ClearScreen()
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  //SetConsoleCursorPosition ( h, coord );
  return;
}

void SetColor(int color)
{
	static HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	switch(color)
	{
	case 1:
		SetConsoleTextAttribute(hOut,FOREGROUND_RED);
		break;
	case 2:
		 SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	case 3:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_GREEN);
		break;
	case 4:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_GREEN |
                            FOREGROUND_INTENSITY);
		break;
	case 5:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_BLUE);
							break;
	case 6:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_BLUE |
                            FOREGROUND_INTENSITY);
							break;
	case 7:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_RED |
                            FOREGROUND_GREEN);
							break;
	case 8:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_RED |
                            FOREGROUND_GREEN |
                            FOREGROUND_INTENSITY);
							break;
	case 9:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE);
							break;
	case 10:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE |
                            FOREGROUND_INTENSITY);
							break;
	case 11:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_BLUE |
                            FOREGROUND_RED);
							break;
	case 12:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_BLUE |
                            FOREGROUND_RED |
                            FOREGROUND_INTENSITY);
							break;
	case 13:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_RED |
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE);
							break;
	case 14:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_RED |
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE |
                            FOREGROUND_INTENSITY);
							break;
	default:
		SetConsoleTextAttribute(hOut,
                            FOREGROUND_RED |
                            FOREGROUND_GREEN |
                            FOREGROUND_BLUE);
							break;
	};

}

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}
