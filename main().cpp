/*
* ������ʹ��ideΪvs2019�� Windows SDK�汾Ϊ10.0.18362.0��ƽ̨���߼�ΪVisual Studio 2019 (v142)�����ļ��谲װeaxyX
* ������Ҫ������ͼƬ�ļ�����ڳ����ļ���ǰĿ¼�£����ɵ������ļ�Ҳ�ᱣ���ڵ�ǰĿ¼��
*/

#include<iostream>
#include<ctime>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<graphics.h>
using namespace std;

class Number
{
private:
	int red[6];                                                           //������������                               
	int blue;                                                             //��������
public:
	void write(int* a, int b);                                            //¼���������������
	int read_ball(int* a);                                                //�������������ĸ���
};
class Lottery_ticket :public Number
{
private:
	int quantity;                                                         //���Ų�Ʊ��ע��
	int red_num;                                                          //�������
	int blue_num;                                                         //�������
	int* red_ball;                                                        //��ź������ֵ�����
	int* blue_ball;                                                       //����������ֵ�����
	Number* lotterynum;                                                   //��Ʊ
public:
	Lottery_ticket(int red, int blue);
	void draw();
	void write(int* red, int* blue);                                       //¼���������������
	void read_ticket(int* red, int* blue);                                 //������������������
	int read_red_num();                                                    //�������
	int read_blue_num();                                                   //�������
	int read_quantity();                                                   //��Ʊע��
	Number read_ticket_num(int i);                                         //������ע��Ʊ
	~Lottery_ticket();                                                     //��������ɾ����ע��Ʊ����
};

void menu(int t, int* data);                                                //���ɲ˵�
void Generatenum(int red_number, int blue_number, int* red, int* blue);     //���ɺ��������
int calculate_quantity(int red, int blue);                                  //�����Ʊע��
int judge(int k, int* a, int length);                                       //�ж�������������ɵ����Ƿ��ظ�
int randf(int* a, int length, int n);                                       //���ɲ��ظ�����                            
void Sort(int* a, int length);                                              //����														   
int probability(int type);													//�������ɸ���
int Prize(Number ticket_num, Number winning_num);                           //�жϽ���
int Singe_Bonus(int num, int price_kind, int* winners_amount, int jackpot); //���㵥ע����
void display1();                                                            //�������
void display2(int jackpot, int people_amount, int sum, int* winner_num, int i);    //���������Ϣ��ʾ
void display3(int jackpot, int people_amount, int sum, int* winner_num, int prize_sum, int i);//������Ϣ��Ӧ��������ʾ
void progress(int i);                                                       //��������
void compare_rand_num(Number* rand, Number winning);                        //ͼ�ν��������ɵ��������������
void displaywinning_num(int* red_temp, int* blue_temp);                     //����񽱺�����ʾ
void displayrand_num(Number* rand);                                                     //�������������ʾ
void display_data();                                                        //��ʾ��������
void ready(int* choose);                                                    //����ѡ���ܵ�
void start(int* choose);                                                    //��ʼִ������

////////////////////////////////////////////////////////////////////////////
int main()
{
	srand(time(NULL));
	int choose[4];
	do
	{
		ready(choose);
		start(choose);
	} while (1);

}
////////////////////////////////////////////////////////////////////////////


void Number::write(int* a, int b)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		red[i] = a[i];
	}
	blue = b;
}
int Number::read_ball(int* a)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		a[i] = red[i];
	}
	return blue;
}
Lottery_ticket::Lottery_ticket(int red = 6, int blue = 1)
{
	red_num = red;
	blue_num = blue;
	quantity = calculate_quantity(red_num, blue_num);
	red_ball = new int[red_num];
	blue_ball = new int[blue_num];
	Generatenum(red_num, blue_num, red_ball, blue_ball);
	lotterynum = new Number[quantity];
}
Lottery_ticket::~Lottery_ticket()
{
	delete lotterynum;
}

void Lottery_ticket::draw()
{
	int i[6] = { 0,1,2,3,4,5 }, temp[6];
	int j, k, t = 0;
	for (; i[0] < i[1]; i[0]++)
	{
		for (i[1] = i[0] + 1; i[1] < i[2]; i[1]++)
		{
			for (i[2] = i[1] + 1; i[2] < i[3]; i[2]++)
			{
				for (i[3] = i[2] + 1; i[3] < i[4]; i[3]++)
				{
					for (i[4] = i[3] + 1; i[4] < i[5]; i[4]++)
					{
						for (i[5] = i[4] + 1; i[5] < red_num; i[5]++)
						{
							for (j = 0; j < blue_num; j++)
							{
								for (k = 0; k < 6; k++)
								{
									temp[k] = red_ball[i[k]];
								}
								lotterynum[t].write(temp, blue_ball[j]);
								t++;
							}
						}
					}
				}
			}
		}
	}
}
void Lottery_ticket::write(int* red, int* blue)
{
	int i;
	for (i = 0; i < red_num; i++)
	{
		red_ball[i] = red[i];
	}
	for (i = 0; i < blue_num; i++)
	{
		blue_ball[i] = blue[i];
	}
}
void Lottery_ticket::read_ticket(int* red, int* blue)
{
	int i;
	for (i = 0; i < red_num; i++)
	{
		red[i] = red_ball[i];
	}
	for (i = 0; i < blue_num; i++)
	{
		blue[i] = blue_ball[i];
	}
}
int Lottery_ticket::read_red_num()
{
	return red_num;
}
int Lottery_ticket::read_blue_num()
{
	return blue_num;
}
int Lottery_ticket::read_quantity()
{
	return quantity;
}
Number Lottery_ticket::read_ticket_num(int i)
{
	return lotterynum[i];
}

//�ж�������������ɵ����Ƿ��ظ�
int judge(int k, int* a, int length)//k������ȡ��һ��������֣�length�������鳤��
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (k == a[i])
			break;
	}
	if (i == length)
		return 0;
	else
		return 1;
}

//���ɲ��ظ�����
int randf(int* a, int length, int n)//length�������鳤�ȣ�n�����������������ѡȡ���ֵ
{
	int k;
	do {
		k = 1 + (int)(n) * (double)rand() / (32767 + 1);
	} while (judge(k, a, length));
	return k;
}

//�����Ʊע��
int calculate_quantity(int red, int blue)
{
	switch (red)
	{
	case 6:
		return 1 * blue;
	case 7:
		return 7 * blue;
	case 8:
		return 28 * blue;
	case 9:
		return 84 * blue;
	case 10:
		return 210 * blue;
	case 11:
		return 462 * blue;
	case 12:
		return 924 * blue;
	case 13:
		return 1716 * blue;
	case 14:
		return 3003 * blue;
	case 15:
		return 5005 * blue;
	case 16:
		return 8008 * blue;
	}
	return 0;
}

//����
void Sort(int* a, int length)             //������a����,length������Ԫ������
{
	for (int i = 0; i < length; i++) {
		int k = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			int temp;
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}

//���ɺ��������
void Generatenum(int red_number, int blue_number, int* red, int* blue)
{
	int  i, j;
	for (i = 0; i < red_number; i++)
		red[i] = randf(red, red_number, 33);
	for (j = 0; j < blue_number; j++)
		blue[j] = randf(blue, blue_number, 16);
	//Sort(red, red_number);
	//Sort(blue, blue_number);
}

//������ĸ���type==0ʱΪ����type!=0ʱΪ����
int probability(int type)
{
	int k, p;
	k = (rand() % 10) + 10 * (rand() % 10) + 100 * (rand() % 10) + 1000 * (rand() % 10) + 10000 * (rand() % 10) + 100000 * (rand() % 10);
	if (k > 200000)
	{
		p = 1;
	}
	else if (k > 100000)
	{
		p = 2;
	}
	else if (k > 50000)
	{
		p = 3;
	}
	else if (k > 25000)
	{
		p = 4;
	}
	else if (k > 12500)
	{
		p = 5;
	}
	else if (k > 6250)
	{
		p = 6;
	}
	else if (k > 3125)
	{
		p = 7;
	}
	else if (k > 1562)
	{
		p = 8;
	}
	else if (k > 781)
	{
		p = 9;
	}
	else if (k > 390)
	{
		p = 10;
	}
	else if (k > 195)
	{
		p = 11;
	}
	else if (k > 97)
	{
		p = 12;
	}
	else if (k > 48)
	{
		p = 13;
	}
	else if (k > 24)
	{
		p = 14;
	}
	else if (k > 12)
	{
		p = 15;
	}
	else
	{
		p = 16;
	}
	if (!type)
	{
		if (p < 6)
			return 6;
		else
			return p;
	}
	else
	{
		return p;
	}
}

//���㽱�����
int Prize(Number ticket_num, Number winning_num)
{
	int winning_rednum[6], winning_bluenum, ticket_rednum[6], ticket_bluenum, i, j, equal_red = 0, equal_blue;//����ֱ�Ϊ�񽱺���ĺ�������򣬹���ĺ��������equal_red��equal_blueΪ�н�������
	winning_bluenum = winning_num.read_ball(winning_rednum);
	ticket_bluenum = ticket_num.read_ball(ticket_rednum);
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (ticket_rednum[j] == winning_rednum[i])
				equal_red++;
		}
	}
	if (winning_bluenum == ticket_bluenum)
		equal_blue = 1;
	else
		equal_blue = 0;
	if (equal_red == 6 && equal_blue == 1)
		return 1;
	else if (equal_red == 6 && equal_blue == 0)
		return 2;
	else if (equal_red == 5 && equal_blue == 1)
		return 3;
	else if (equal_red == 5 && equal_blue == 0 || equal_red == 4 && equal_blue == 1)
		return 4;
	else if (equal_red == 4 && equal_blue == 0 || equal_red == 3 && equal_blue == 1)
		return 5;
	else if (equal_red == 2 && equal_blue == 1 || equal_red == 1 && equal_blue == 1 || equal_red == 0 && equal_blue == 1)
		return 6;
	else
		return 0;
}

//���㵥ע����
int Singe_Bonus(int num, int price_kind, int* winners_amount, int jackpot)
{
	int bet_amount, low_prize = 0, bonus2, bonus1, top_prize, t1, t2, t3, standard = 5000000;//����ֱ�����ע�����͵Ƚ����𣬶��Ƚ�����һ�Ƚ����𣬸ߵȽ�����
	bet_amount = 2 * num;
	top_prize = bet_amount - winners_amount[5] * 5 - winners_amount[4] * 10 - winners_amount[3] * 200 - winners_amount[2] * 3000;//����ߵȽ�����
	bonus2 = int((top_prize * 0.3) / winners_amount[1]);
	t1 = int((top_prize * 0.7 + jackpot) / winners_amount[0]);
	t2 = int((top_prize * 0.5 + jackpot) / winners_amount[0]);
	t3 = int((top_prize * 0.2) / winners_amount[0]);
	if (jackpot < 100000000)                           //���ڽ����Ƿ�1�ڽ����жϣ��ֱ𷵻ض�Ӧ�Ľ���
	{
		if (t1 <= standard)
			bonus1 = t1;
		else
			bonus1 = standard;
	}
	else
	{
		if (t2 <= standard && t3 <= standard)
			bonus1 = t2 + t3;
		else if (t2 > standard && t3 <= standard)
			bonus1 = standard + t3;
		else if (t2 > standard && t3 > standard)
			bonus1 = 2 * standard;
		else if (t2 <= standard && t3 > standard)
			bonus1 = t2 + standard;
	}
	switch (price_kind)
	{
	case 6:
		return 5;
	case 5:
		return 10;
	case 4:
		return 200;
	case 3:
		return 3000;
	case 2:
		return bonus2;
	case 1:
		return bonus1;
	}
	return 0;
}

//��������
void progress(int i)
{
	TCHAR temp1[10];
	solidrectangle(756, 171, i * 3 + 756, 199);
	_stprintf_s(temp1, _T("�����%d%%"), i);
	outtextxy(1080, 170, temp1);
}

void display1()
{
	initgraph(1300, 800);
	setbkcolor(WHITE);
	cleardevice();
	LOGFONT f;
	settextcolor(BLACK);
	gettextstyle(&f);
	f.lfHeight = 70;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	outtextxy(170, 40, _T("��ӭ����˫ɫ��ģ�⿪������"));
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(320, 165, _T("�������"));
	_tcscpy_s(f.lfFaceName, _T("����"));
	setbkmode(TRANSPARENT);
	settextstyle(&f);


}

void display2(int jackpot, int people_amount, int bet_sum, int* winner_num, int i)
{
	TCHAR temp[50];
	outtextxy(790, 220, _T("(���ո���ֹ����)"));
	setlinecolor(0x000000);
	rectangle(755, 170, 1057, 200);
	setfillcolor(0xFFCC66);
	_stprintf_s(temp, _T("���أ�%d"), jackpot);
	outtextxy(800, 270, temp);
	_stprintf_s(temp, _T("��������%d/%d"), i, people_amount);
	outtextxy(800, 310, temp);
	_stprintf_s(temp, _T("��ע����%d"), bet_sum);
	outtextxy(800, 350, temp);
	_stprintf_s(temp, _T("һ�Ƚ�ע����%d"), winner_num[0]);
	outtextxy(800, 390, temp);
	_stprintf_s(temp, _T("���Ƚ�ע����%d"), winner_num[1]);
	outtextxy(800, 430, temp);
	_stprintf_s(temp, _T("���Ƚ�ע����%d"), winner_num[2]);
	outtextxy(800, 470, temp);
	_stprintf_s(temp, _T("�ĵȽ�ע����%d"), winner_num[3]);
	outtextxy(800, 510, temp);
	_stprintf_s(temp, _T("��Ƚ�ע����%d"), winner_num[4]);
	outtextxy(800, 550, temp);
	_stprintf_s(temp, _T("���Ƚ�ע����%d"), winner_num[5]);
	outtextxy(800, 590, temp);
	_stprintf_s(temp, _T("��Ͷ�ʣ�%d"), bet_sum * 2);
	outtextxy(800, 630, temp);
}

void display3(int jackpot, int people_amount, int bet_sum, int* winner_num, int prize_sum, int i)
{
	TCHAR temp[50];
	_stprintf_s(temp, _T("���أ�%d"), jackpot);
	outtextxy(800, 270, temp);
	_stprintf_s(temp, _T("��������%d/%d"), i, people_amount);
	outtextxy(800, 310, temp);
	_stprintf_s(temp, _T("��ע����%d"), bet_sum);
	outtextxy(800, 350, temp);
	_stprintf_s(temp, _T("һ�Ƚ�ע����%d"), winner_num[0]);
	outtextxy(800, 390, temp);
	_stprintf_s(temp, _T("���Ƚ�ע����%d"), winner_num[1]);
	outtextxy(800, 430, temp);
	_stprintf_s(temp, _T("���Ƚ�ע����%d"), winner_num[2]);
	outtextxy(800, 470, temp);
	_stprintf_s(temp, _T("�ĵȽ�ע����%d"), winner_num[3]);
	outtextxy(800, 510, temp);
	_stprintf_s(temp, _T("��Ƚ�ע����%d"), winner_num[4]);
	outtextxy(800, 550, temp);
	_stprintf_s(temp, _T("���Ƚ�ע����%d"), winner_num[5]);
	outtextxy(800, 590, temp);
	_stprintf_s(temp, _T("��Ͷ�ʣ�%d"), bet_sum * 2);
	outtextxy(800, 630, temp);
	_stprintf_s(temp, _T("���н���%d"), prize_sum);
	outtextxy(800, 670, temp);
	_stprintf_s(temp, _T("�ر��ʣ�%.2f%%"), (float)prize_sum / (bet_sum * 2) * 100);
	outtextxy(800, 710, temp);
}
//���������ʾ

void displayrand_num(Number* rand_ticket)
{
	int i, j, x, y;
	int redrand[6], bluerand[1];
	IMAGE img1, img2;
	TCHAR num[7];
	loadimage(&img1, _T("./����2.jpg"));
	loadimage(&img2, _T("./����2.jpg"));
	do
	{
		do
		{
			BeginBatchDraw();
			for (x = 210; x < 510; x += 50)
			{
				for (y = 230; y < 480; y += 50)
				{
					putimage(x, y, &img1);

				}
			}
			for (x = 230; x < 480; x += 50)
			{

				putimage(510, x, &img2);
			}
			for (i = 0; i < 5; i++)
			{
				Generatenum(6, 1, redrand, bluerand);
				rand_ticket[i].write(redrand, bluerand[0]);
				for (j = 0; j < 6; j++)
				{
					num[j] = redrand[j];
					_stprintf_s(num, _T("%02d"), num[j]);
					outtextxy(216 + 50 * j, 235 + 50 * i, num);
				}
				num[6] = bluerand[0];
				_stprintf_s(num, _T("%02d"), num[6]);
				outtextxy(516, 235 + 50 * i, num);
			}
			Sleep(50);
			EndBatchDraw();
		} while (!_kbhit());
	} while (_getch() != 32);
}
//������뽱��ȶ�
void compare_rand_num(Number* rand_ticket, Number winning)
{
	int i, price_kind;
	for (i = 0; i < 5; i++)
	{
		price_kind = Prize(rand_ticket[i], winning);
		switch (price_kind)
		{
		case 1:
			outtextxy(600, 235 + 50 * i, _T("һ�Ƚ�"));
			break;
		case 2:
			outtextxy(600, 235 + 50 * i, _T("���Ƚ�"));
			break;
		case 3:
			outtextxy(600, 235 + 50 * i, _T("���Ƚ�"));
			break;
		case 4:
			outtextxy(600, 235 + 50 * i, _T("�ĵȽ�"));
			break;
		case 5:
			outtextxy(600, 235 + 50 * i, _T("��Ƚ�"));
			break;
		case 6:
			outtextxy(600, 235 + 50 * i, _T("���Ƚ�"));
			break;
		case 0:
			outtextxy(600, 235 + 50 * i, _T("û���н�"));
			break;
		}
	}
}

//�񽱺�����ʾ
void displaywinning_num(int* red_temp, int* blue_temp)
{
	LOGFONT f;
	IMAGE img;
	TCHAR num[7];
	settextcolor(BLACK);
	gettextstyle(&f);
	f.lfHeight = 60;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	setbkmode(TRANSPARENT);
	settextstyle(&f);
	outtextxy(260, 530, _T("�񽱺���"));
	Sleep(50);
	loadimage(&img, _T("./����.jpg"));
	for (int m = 0, k = 40; m < 6, k <= 590; k += 100, m++)
	{
		putimage(k, 640, &img);
		num[m] = red_temp[m];
		_stprintf_s(num, _T("%02d"), num[m]);
		outtextxy(50 + 100 * m, 650, num);
		Sleep(500);
	}
	loadimage(&img, _T("./����.jpg"));
	putimage(640, 640, &img);
	num[6] = blue_temp[0];
	_stprintf_s(num, _T("%02d"), num[6]);
	outtextxy(650, 650, num);
	Sleep(500);
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("����"));
	setbkmode(OPAQUE);
	settextstyle(&f);
	setlinecolor(0x000000);
	rectangle(755, 170, 1057, 200);
	setfillcolor(0xFFCC66);
}

//�˵�
void menu(int t, int* data)
{
	system("Cls");
	int i;
	for (i = 0; i < 50; i++)
	{
		cout << "*";
	}
	cout << endl << "*";
	for (i = 0; i < 48; i++)
	{
		cout << " ";
	}
	cout << "*" << endl << "*";
	for (i = 0; i < 12; i++)
	{
		cout << " ";
	}
	cout << "��ӭʹ��˫ɫ��ģ�����";
	for (i = 0; i < 12; i++)
	{
		cout << " ";
	}
	cout << "*" << endl << "*";
	for (i = 0; i < 48; i++)
	{
		cout << " ";
	}
	cout << "*" << endl;
	for (i = 0; i < 50; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "��ǰ��������" << data[0] << "��" << endl;
	cout << "��ǰ���أ�" << data[3] << endl;;
	switch (data[1])
	{
	case 0:
		cout << "��ǰ������Χ��10-100" << endl;
		break;
	case 1:
		cout << "��ǰ������Χ��10000-100000" << endl;
		break;
	case 2:
		cout << "��ǰ������Χ��10000000-100000000" << endl;
		break;
	}
	if (!data[2])
	{
		cout << "��ʾʵʱ���ݣ�������" << endl;
	}
	else
	{
		cout << "����ʾʵʱ���ݣ��Ͽ죩" << endl;
	}

	for (i = 0; i < 50; i++)
	{
		cout << "*";
	}
	cout << endl;
	switch (t)
	{
	case 1:
		cout << "[1]��ʼִ�г���" << endl << "[2]�޸Ĳ���" << endl << "[3]��������" << endl << "[0]�˳�����" << endl;
		for (i = 0; i < 50; i++)
		{
			cout << "*";
		}
		cout << endl;
		break;
	case 2:
		cout << "[0]�������" << endl << "[1]�޸Ľ���" << endl << "[2]�޸�������Χ" << endl;
		if (data[2])
		{
			cout << "[3]��ʾʵʱ���ݣ�������" << endl;
		}
		else
		{
			cout << "[3]����ʾʵʱ���ݣ��Ͽ죩" << endl;
		}
		cout << "[4]�˳��޸�" << endl;
		for (i = 0; i < 50; i++)
		{
			cout << "*";
		}
		cout << endl;
		break;
	case 3:
		cout << "��ȷ��Ҫ���������" << endl << "[0]ȷ��" << endl << "[1]ȡ��" << endl;
		for (i = 0; i < 50; i++)
		{
			cout << "*";
		}
		cout << endl;
		break;
	case 4:
		cout << "���뽱�ؽ�(0-1,0000,0000,0000)" << endl;
		break;
	case 5:
		cout << "[0]ѡ��С��Χ��10-100��" << endl << "[1]ѡ���Χ��1000-10000��" << endl << "[2]ѡ�񳬴�Χ��10000000-100000000��" << endl << "[3]�˳��޸�" << endl;
		for (i = 0; i < 50; i++)
		{
			cout << "*";
		}
		cout << endl;
		break;
	case 6:
		cout << "���������ַ�����" << endl;
		for (i = 0; i < 50; i++)
		{
			cout << "*";
		}
		cout << endl;
		break;
	}
}

void display_data()
{
	int data[13], i;
	double a;
	char p;
	ifstream data_i("./data.txt");
	data_i.seekg(0, ios::beg);
	cout << setw(10) << "����" << setw(11) << "����" << setw(11) << "������" << setw(11) << "��ע��" << setw(11) << "һ�Ƚ�" << setw(11) << "���Ƚ�" << setw(11) << "���Ƚ�" << setw(11) << "�ĵȽ�" << setw(11) << "��Ƚ�" << setw(11) << "���Ƚ�" << setw(11) << "��Ͷ��" << setw(11) << "���н�" << setw(11) << "�ر���";
	cout << endl;
	while (!data_i.eof())
	{
		data_i.get(p);
		if (p == '#')
		{
			p = '\n';
		}
		else
		{
			cout << endl << "�����ĵ�����" << endl;
			return;
		}
		for (i = 0; i < 12; i++)
		{
			data_i >> data[i];
			cout << setw(10) << data[i] << " ";
		}
		a = 100 * (double)data[11] / data[10];
		cout << setw(10) << setprecision(4) << a << "% ";
		cout << endl;

	}
	data_i.close();
}


void ready(int* choose)
{
	ofstream data_o("./data.txt", ios::out | ios::app);
	data_o.close();
	ifstream data_i("./data.txt", ios::in);
	int i, ch, t = 0, data_temp[6];
	double temp;
	char p = ' ';
	data_i.seekg(0, ios::end);
	streampos fp = data_i.tellg();
	data_i.seekg(0, ios::beg);
	if (int(fp) == 0)
	{
		data_temp[0] = 1;
		data_temp[1] = 0;
		data_temp[2] = 0;
		data_temp[3] = 10000000;
		data_temp[4] = 0;
		data_temp[5] = 0;
	}
	else
	{
		for (i = -1; 1; i--)
		{
			data_i.seekg(i, ios::end);
			data_i.get(p);
			if (p == '#')
				break;
		}
		data_i >> data_temp[0] >> data_temp[3] >> i >> i >> i >> i >> i >> i >> i >> i >> data_temp[4] >> data_temp[5];
		data_i.close();
		data_temp[0]++;
		data_temp[1] = 0;
		data_temp[2] = 0;
		data_temp[3] += data_temp[4] - data_temp[5];
	}
	do
	{
		menu(1, data_temp);//�ܲ˵�
		do
		{
			ch = _getch();
		} while (ch != 48 && ch != 49 && ch != 50 && ch != 51);

		switch (ch)
		{
		case 48:
			exit(0);
		case 49:
			break;
		case 50:                                                                  //�޸�����
			menu(2, data_temp);
			do
			{
				ch = _getch();
			} while (ch != 48 && ch != 49 && ch != 50 && ch != 51 && ch != 52);
			switch (ch)
			{
			case 48:
				menu(3, data_temp);
				do
				{
					ch = _getch();
					if (ch == 48)
					{
						ofstream fileout("./data.txt", ios::out | ios::trunc);
						fileout.close();
						data_temp[0] = 1;
						data_temp[1] = 0;
						data_temp[2] = 0;
						data_temp[3] = 10000000;
						data_temp[4] = 0;
						data_temp[5] = 0;
						break;
					}
				} while (ch == 49);
				break;
			case 49:
				menu(4, data_temp);
				cin >> temp;
				//cin.clear();
				//cin.ignore();
				while (temp < 0 || temp > 1000000000)
				{
					//cin.clear();
					//cin.ignore();
					menu(4, data_temp);
					cin >> temp;
				}
				data_temp[3] = temp;
				break;
			case 50:
				menu(5, data_temp);
				do
				{
					ch = _getch();
				} while (ch != 48 && ch != 49 && ch != 50 && ch != 51);
				switch (ch)
				{
				case 48:
					data_temp[1] = 0;
					break;
				case 49:
					data_temp[1] = 1;
					break;
				case 50:
					data_temp[1] = 2;
					break;
				case 51:
					break;
				}
				break;
			case 51:
				data_temp[2] = ++data_temp[2] % 2;
				menu(2, data_temp);
				break;
			case 52:
				break;
			}
			ch = 0;
			break;
		case 51:
			menu(6, data_temp);
			display_data();
			_getch();
			ch = 0;
			break;
		}



	} while (ch != 49);
	for (i = 0; i < 4; i++)
	{
		choose[i] = data_temp[i];
	}
}

//��ʼִ������
void start(int* choose)
{
	display1();
	LOGFONT f;
	Lottery_ticket* ticket;
	Number winning, rand_ticket[5];
	int red_temp[6], blue_temp[1], red_num_temp, blue_num_temp;
	int people_amount, winner_num[6] = { 0 }, prize_kind, bet_sum = 0, prize_sum = 0;
	int i, j, k, quantity_temp, prize_temp, data_temp[15];
	displayrand_num(rand_ticket);
	for (i = 0; i < 4; i++)
	{
		data_temp[i] = choose[i];
	}
	switch (data_temp[1])
	{
	case 0:
		people_amount = rand() % 90 + 11;
		break;
	case 1:
		people_amount = rand() % 10000 + 10000 * (rand() % 10);
		break;
	case 2:
		people_amount = rand() % 10000 + 10000 * (rand() % 10000);
		break;
	}
	//people_amount = 0;
	Generatenum(6, 1, red_temp, blue_temp);
	winning.write(red_temp, *blue_temp);
	displaywinning_num(red_temp, blue_temp);
	gettextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("����"));
	setbkmode(OPAQUE);
	settextstyle(&f);
	compare_rand_num(rand_ticket, winning);
	for (i = 0; i < people_amount; i++)
	{
		do
		{
			red_num_temp = probability(0);
			blue_num_temp = probability(1);
			quantity_temp = calculate_quantity(red_num_temp, blue_num_temp);
		} while (quantity_temp > 10000);
		ticket = new Lottery_ticket(red_num_temp, blue_num_temp);
		ticket->draw();
		bet_sum += ticket->read_quantity();
		k = ticket->read_quantity();
		for (j = 0; j < k; j++)
		{
			prize_kind = Prize(winning, ticket->read_ticket_num(j));
			switch (prize_kind)
			{
			case 1:
				winner_num[0]++;
				break;
			case 2:
				winner_num[1]++;
				break;
			case 3:
				winner_num[2]++;
				break;
			case 4:
				winner_num[3]++;
				break;
			case 5:
				winner_num[4]++;
				break;
			case 6:
				winner_num[5]++;
			}
		}
		delete ticket;
		if (!data_temp[2])
		{
			display2(data_temp[3], people_amount, bet_sum, winner_num, i);
		}
		progress(100 * ((double)i / people_amount));
		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 32)
				break;
		}
	}
	for (j = 0; j < 6; j++)
	{
		prize_sum += Singe_Bonus(bet_sum, j + 1, winner_num, data_temp[3]) * winner_num[j];
	}
	prize_temp = 2 * bet_sum;
	ofstream data_o("./data.txt", ios::out | ios::app);
	data_o << '#' << " " << data_temp[0] << " " << data_temp[3] << " " << i << " " << bet_sum << " " << winner_num[0] << " " << winner_num[1] << " " << winner_num[2] << " " << winner_num[3] << " " << winner_num[4] << " " << winner_num[5] << " " << prize_temp << " " << prize_sum;
	data_o.close();
	if (i < people_amount)
	{
		progress(100 * ((double)i / people_amount));
	}
	else
	{
		progress(100);
	}
	display3(data_temp[3], people_amount, bet_sum, winner_num, prize_sum, i);
	for (i = 0; i < 4; i++)
	{
		choose[i] = 0;
	}
	outtextxy(790, 220, _T("(���������������)"));
	_getch();
	closegraph();
}
