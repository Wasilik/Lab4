#include <math.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

void task102(void)
{
    int n;
    double population = 0, area = 0;

    printf("Кількість районів: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;

    for (int i = 0; i < n; ++i) {
        double people, square;
        printf("Район %d: населення (тис. осіб) і площа (км²): ", i + 1);
        if (scanf("%lf %lf", &people, &square) != 2 ||
            people < 0 || square <= 0) return;
        population += people;
        area += square;
    }
    printf("Середня щільність: %.6g осіб/км²\n", 1000 * (population / area));
}

int is_prime(int n)
{
    if (n < 2) return 0;
    for (int d = 2; d <= n / d; ++d) {
        if (n % d == 0) return 0;
    }
    return 1;
}

void task109(void)
{
    int all_prime = 1;

    for (int x = 0; x <= 15; ++x) {
        int y = x * x + x + 17;
        int prime = is_prime(y);
        printf("x = %2d: %3d — %s\n", x, y, prime ? "просте" : "складене");
        if (!prime) all_prime = 0;
    }
    puts(all_prime ? "Усі результати прості." : "Є складені числа.");
}

void task128(void)
{
    for (int n = 10; n <= 99; ++n) {
        int tens = n / 10, units = n % 10;
        if (n == units * units + tens * tens * tens) printf("%d\n", n);
    }
}

void task165(void)
{
    long long n;
    int m, sum = 0;

    printf("Введіть натуральне число і кількість останніх цифр m: ");
    if (scanf("%lld %d", &n, &m) != 2 || n <= 0 || m <= 0) return;

    while (m > 0 && n > 0) {
        sum += (int)(n % 10);
        n /= 10;
        --m;
    }
    if (m > 0) {
        puts("У числі менше ніж m цифр.");
        return;
    }
    printf("Сума: %d\n", sum);
}

void task226(void)
{
    double a, b, h;

    printf("Введіть a, b і крок h: ");
    if (scanf("%lf %lf %lf", &a, &b, &h) != 3 || a > b || h <= 0) return;

    printf("%15s %15s\n", "x", "F(x)");
    double tolerance = h / 1000000;
    for (int i = 0; a + i * h <= b + tolerance; ++i) {
        double x = a + i * h;
        if (x > b) x = b;
        printf("%15.9g %15.9g\n", x, 2 * cos(x) - 1);
        if (x == b) break;
    }
}

void task37(void)
{
    int n;
    double product = 1;

    printf("Введіть натуральне n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;

    for (int i = 0; i < n; ++i) product *= 1 - 1 / (2.0 * (i + 1));
    printf("P = %.10g\n", product);
}

void task164(void)
{
    long long n;
    int position = 1;

    printf("Введіть натуральне число: ");
    if (scanf("%lld", &n) != 1 || n <= 0) return;

    while (n > 0 && n % 10 != 3) {
        n /= 10;
        ++position;
    }
    printf("Позиція цифри 3: %d\n", n > 0 ? position : 0);
}

void task53(void)
{
    int term = 4, sum = 0;

    for (int exponent = 2; exponent <= 10; ++exponent) {
        sum += term;
        term *= 2;
    }
    printf("Сума: %d\n", sum);
}

void task270(void)
{
    long long distinct = 0, repeated = 0, group_size = 0;
    int value, previous = 0;

    puts("Введіть неспадну послідовність. Число 1000 завершує введення.");
    do {
        if (scanf("%d", &value) != 1) return;
        if (value == 1000) break;
        if (group_size == 0 || value != previous) {
            if (group_size > 1) repeated += group_size;
            ++distinct;
            group_size = 1;
            previous = value;
        } else {
            ++group_size;
        }
    } while (value != 1000);

    if (group_size > 1) repeated += group_size;
    printf("Елементів у групах повторів: %lld\n", repeated);
    printf("Різних чисел: %lld\n", distinct);
}

void task261(void)
{
    const double a = 1, b = -2;

    printf("%5s %15s\n", "x", "y");
    for (int half = -2; half <= 10; ++half) {
        double x = half / 2.0;
        double denominator = 2 * a - b * x;
        double distance = fabs(a - x);

        if (denominator == 0 || distance == 0) {
            printf("%5.1f  не визначено\n", x);
        } else {
            double y = 0.3 * a * b * x / denominator
                     - 3 * sqrt((2 * a - atan(x)) / distance);
            printf("%5.1f %15.8f\n", x, y);
        }
    }
}

int main(void)
{
    int choice;
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    puts("Лабораторна робота №4 — циклічні алгоритми");
    puts("1 — №102: щільність населення");
    puts("2 — №109: перевірка простих чисел");
    puts("3 — №128: двозначне число");
    puts("4 — №165: сума останніх цифр");
    puts("5 — №226: таблиця F(x) = 2 cos(x) - 1");
    puts("6 — №37: добуток");
    puts("7 — №164: позиція цифри 3");
    puts("8 — №53: сума степенів двійки");
    puts("9 — №270: повтори в послідовності");
    puts("10 — №261: таблиця значень функції");
    printf("Виберіть завдання: ");

    if (scanf("%d", &choice) != 1) return 1;
    switch (choice) {
        case 1: task102(); break;
        case 2: task109(); break;
        case 3: task128(); break;
        case 4: task165(); break;
        case 5: task226(); break;
        case 6: task37(); break;
        case 7: task164(); break;
        case 8: task53(); break;
        case 9: task270(); break;
        case 10: task261(); break;
        default: puts("Невідомий номер завдання."); return 1;
    }
    return 0;
}
