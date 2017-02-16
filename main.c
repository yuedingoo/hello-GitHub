//猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void data_guess()
{
	int level,i,data_guess;
	printf("start the guess game,please choose the game level(1-Lv1,2-Lv2,3-Lv3):\n");
loop:
	fflush(stdin);
	scanf("%d", &level);
	switch (level)
	{
	case 1:
		printf("the game level is Lv1!\n");
		level = 20;
		break;
	case 2:
		printf("the game level is Lv2!\n");
		level = 10;
		break;
	case 3:
		printf("the game level is Lv3!\n");
		level = 5;
		break;
	default:
		printf("error input,please try again(1-Lv1,2-Lv2,3-Lv3)");
		goto loop;
	}
	printf("Ready!!!\n");
	for (i = 3; i > 0; i--)
	{
		Sleep(1000);
		printf("...%d...\n", i);
	}
	srand((unsigned)time(NULL));
    data_guess = (rand()%9000 + 1000);   // 0-8999   1000-9999

	//printf("the guess number is %d\n",data_guess);   //正确数字


	while (level--)
	{
		int use_data;
		printf("please guess the number:");
		scanf("%d",&use_data);
		if (data_guess == use_data)
		{
			printf("congralations!you are right.");
			break;
		}
		else
		{
			if ((use_data % 10) == (data_guess % 10))
				printf("个位数正确\n");
			else if ((use_data % 10) > (data_guess % 10))
				printf("个位数大了\n");
			else
				printf("个位数小了\n");

			if ((use_data /10 % 10) == (data_guess /10 % 10))
				printf("十位数正确\n");
			else if ((use_data /10 % 10) > (data_guess /10 % 10))
				printf("十位数大了\n");
			else
				printf("十位数小了\n");

			if ((use_data / 100 % 10) == (data_guess / 100 % 10))
				printf("百位数正确\n");
			else if ((use_data / 100 % 10) > (data_guess / 100 % 10))
				printf("百位数大了\n");
			else
				printf("百位数小了\n");

			if ((use_data / 1000) == (data_guess / 1000))
				printf("千位数正确\n");
			else if ((use_data / 1000) > (data_guess / 1000))
				printf("千位数大了\n");
			else
				printf("千位数小了\n");
		}
	}

}

int main()
{
	data_guess();

	return 0;
}
