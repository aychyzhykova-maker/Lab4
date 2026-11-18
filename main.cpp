#include <iostream>
#include <cmath>
using namespace std;


// ---------- оголошення функцій ----------

// Proc46
// введення кола з перевіркою (true - помилка)
bool in_circle(float & px, float & py, float & pr, int n); 
// чи перетинаються два кола
bool circle_intersect(float x1, float y1, float r1,
                      float x2, float y2, float r2); 
// виведення результату Proc46
void out_bool(bool pb); 
// задача Proc46 цілком
void task_proc46();                                     

// Proc6
// введення K з перевіркою (true - помилка)
bool in_K(int & pK);
// кількість і сума цифр (рекурсія, без циклів)
void digit_count_sum(int K, int & C, int & S);  
// виведення результату Proc6
void out_cs(int pK, int pC, int pS);  
// задача Proc6 цілком
void task_proc6();                              

// Integer12
// введення тризначного числа з перевіркою (true - помилка)
bool in_N(int & pN);
// підрахунок Integer12 (число справа наліво)
int reverse_num(int pN);
// виведення результату Integer12
void out_res(int pr);
// задача Integer12 цілком
void task_Int12();                          

// ---------- main ----------
int main()
{
	int choice;
	cout << "Меню:" << endl;
	cout << "1 - Proc46" << endl;
	cout << "2 - Proc6" << endl;
	cout << "3 - Integer12" << endl;
	cout << "Ваш вибір: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		task_proc46();
		break;
	case 2:
		task_proc6();
		break;
	case 3:
		task_Int12();
		break;
	default:
		cout << "Невірний пункт меню!" << endl;
	}

	return 0;
}

// ---------- визначення функцій ----------

// ===== Proc46 =====
bool in_circle(float & px, float & py, float & pr, int n)
{
	cout << "Коло " << n << " (x y R): ";
	cin >> px >> py >> pr;
	// помилка консольного введення
	if (cin.fail())
		return true;
	if (px < -100 || px > 100 || py < -100 || py > 100 || pr < -100 || pr > 100)
		// поза діапазоном [-100,100]
		return true;
	// радіус має бути додатним
	if (pr <= 0)
		return true;
	return false;
}

bool circle_intersect(float x1, float y1, float r1,
                      float x2, float y2, float r2)
{
	float d = hypot(x2 - x1, y2 - y1);
	if (d < r1 + r2 && d > fabs(r2 - r1))
		return true;
	else
		return false;
}

void out_bool(bool pb)
{
	if (pb)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

void task_proc46()
{
	float x1, y1, r1, x2, y2, r2, x3, y3, r3;
	cout << "Proc46." << endl;

	// введення даних
	if (in_circle(x1, y1, r1, 1) || in_circle(x2, y2, r2, 2) || in_circle(x3, y3, r3, 3))
		cout << "Некоректні дані! Координати і R мають бути числами з [-100,100], R > 0." << endl;
	else
	{
		// перевірка трьох пар кіл
		cout << "Кола 1 і 2: ";
		out_bool(circle_intersect(x1, y1, r1, x2, y2, r2));
		cout << "Кола 1 і 3: ";
		out_bool(circle_intersect(x1, y1, r1, x3, y3, r3));
		cout << "Кола 3 і 2: ";
		out_bool(circle_intersect(x3, y3, r3, x2, y2, r2));
	}
}

// ===== Proc6 =====
bool in_K(int & pK)
{
	// помилка консольного введення
	cin >> pK;
	if (cin.fail())
		return true;
	// число має бути цілим додатним
	if (pK <= 0)
		return true;
	return false;
}

//C - кількість цифр, S - сума цифр
void digit_count_sum(int K, int & C, int & S)
{
	if (K == 0)
	{
		C = 0;
		S = 0;
	}
	else
	{
		digit_count_sum(K / 10, C, S);
		C = C + 1;
		S = S + K % 10;
	}
}

void out_cs(int pK, int pC, int pS)
{
	cout << "K = " << pK << ": кількість цифр = " << pC << ", сума цифр = " << pS << endl;
}

void task_proc6()
{
	int k1, k2, k3, k4, k5;
	int c, s;
	cout << "Proc6." << endl;
	cout << "Введіть 5 цілих додатних чисел: ";

	if (in_K(k1) || in_K(k2) || in_K(k3) || in_K(k4) || in_K(k5))
		cout << "Числа мають бути цілими додатними!" << endl;
	else
	{
		digit_count_sum(k1, c, s);
		out_cs(k1, c, s);
		digit_count_sum(k2, c, s);
		out_cs(k2, c, s);
		digit_count_sum(k3, c, s);
		out_cs(k3, c, s);
		digit_count_sum(k4, c, s);
		out_cs(k4, c, s);
		digit_count_sum(k5, c, s);
		out_cs(k5, c, s);
	}
}

// ===== Integer12 =====
bool in_N(int & pN)
{
	cout << "Integer12." << endl;
	cout << "Тризначне число N = ";
	cin >> pN;
	// помилка консольного введення
	if (cin.fail())
		return true;
	// має бути тризначним
	if (abs(pN) < 100 || abs(pN) > 999)
		return true;
	// працюємо з модулем числа
	if (pN < 0)
		pN = -pN;
	return false;
}

int reverse_num(int pN)
{
	return (pN % 10) * 100 + (pN / 10 % 10) * 10 + pN / 100;
}

void out_res(int pr)
{
	cout << "Число справа наліво = " << pr << endl;
}

void task_Int12()
{
	int N;
	if (in_N(N))
		cout << "N має бути тризначним цілим числом!" << endl;
	else
		out_res(reverse_num(N));
}
