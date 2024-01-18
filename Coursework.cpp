#include <iostream>
#include <fstream>

using namespace std;

// Функция для расчета идеальной массы тела по формуле Лоренца
double calculateLorenzIdealWeight(double height)
{
        return (height * 100 - 100) - (height * 100 - 150) / 2;
}

// Функция для расчета ИМТ
double calculateBMI(double weight, double height) 
{
    return weight / (height * height);
}

// Функция для расчета идеального веса по формуле Девинья
double calculateDevine(double height, char gender) 
{
    if (gender == 'М') 
    {
        return 50 + 2.3 * (0.394 * height * 100 - 60);
    }
    else 
    {
        return 45.5 + 2.3 * (0.394 * height * 100 - 60);
    }
}

// Расчет ИМТ с учетом возраста и пола
double calculateBmiGenderBased(double weight, double height, double age, char gender)
{
    if (gender == 'М') 
    {
        return (1.3 * weight) / (0.39 * height - 0.03 * age + 1.6);
    }
    else 
    {
        return (1.3 * weight) / (0.42 * height - 0.03 * age + 1.3);
    }
}

// Расчет Идеальный вес по формуле Брока
double calculateBrok(double height, char gender)
{
    if (gender == 'М')
    {
        return height * 100 - (100 + (height * 100 - 100) / 20);
    }
    else
    {
        return height * 100 - (100 + (height * 100 - 100) / 10);
    }
}

string BMI (double bmi)
{
    string c;
    if (bmi < 16)
    {
        c = "Выраженный дефицит\n";
    }
    else if (bmi > 16 && bmi < 18.5)
    {
        c = "Недостаток массы\n";
    }
    else if (bmi > 18.5 && bmi < 25)
    {
        c = "Норма\n";
    }
    else if (bmi > 25 && bmi < 30)
    {
        c = "Избыток массы\n";
    }
    else if (bmi > 30 && bmi < 35)
    {
        c = "Ожирение 1 степени\n";
    }
    else if (bmi > 35 && bmi < 40)
    {
        c = "Ожирение 2 степени\n";
    }
    else if (bmi > 40 && bmi < 35)
    {
        c = "Ожирение 3 степени\n";
    }
    cout << c;
    return c;
}

int main() 
{
    setlocale(LC_ALL, "RU");
    double weight, height, age;
    char gender;
    cout << "Введите ваш вес в кг: ";
    cin >> weight;
    cout << "Введите ваш рост в м: ";
    cin >> height;
    cout << "Введите ваш возраст: ";
    cin >> age;
    cout << "Введите ваш пол (M/W): ";
    cin >> gender;
    while (gender != 'M' && gender != 'W') 
    {
        cout << "Вы ввели некорректные данные\n";
        cout << "Введите ваш пол (M/W): ";
        cin >> gender;
    }

    double bmi = calculateBMI(weight, height);
    double devine = calculateDevine(height, gender);
    double bmiGenderBased = calculateBmiGenderBased(weight, height, age, gender);
    double lorenzIdealWeight = calculateLorenzIdealWeight(height);
    double Brok = calculateBrok(height, gender);

    // Усредненный результат
    double averageResult = (bmi + devine + bmiGenderBased + lorenzIdealWeight + Brok) / 5.0;
    cout << "Ваш идеальный вес (ИМТ): " << bmi << " кг/м^2 - ";
    BMI(bmi);
    cout << "Ваш идеальный вес по формуле Девинья: " << devine << " кг" << endl;
    cout << "Ваш идеальный вес с учетом возраста и пола: " << bmiGenderBased << " кг/м^2" << endl;
    cout << "Ваш идеальная вес тела по формуле Лоренца: " << lorenzIdealWeight << " кг" << endl;
    cout << "Ваш идеальная вес тела по формуле Брока: " << Brok << " кг" << endl;
    cout << "Усредненный результат: " << averageResult << " кг/м^2" << endl;

    // Сохранение результатов в файл
    ofstream outfile("Result.txt");
    if (outfile.is_open()) 
    {
        outfile << "Ваш идеальный вес (ИМТ): " << bmi << " кг/м^2" << endl;
        outfile << "Ваш идеальный вес по формуле Девинья: " << devine << " кг" << endl;
        outfile << "Ваш идеальный вес с учетом возраста и пола: " << bmiGenderBased << " кг/м^2" << endl;
        outfile << "Ваш идеальная вес тела по формуле Лоренца: " << lorenzIdealWeight << " кг" << endl;
        outfile << "Ваш идеальная вес тела по формуле Брока: " << Brok << " кг" << endl;
        outfile << "Усредненный результат: " << averageResult << " кг/м^2" << endl;
        outfile.close();
    }
    else {
        cout << "Не удалось открыть файл для сохранения результатов" << endl;
    }

    return 0;
}