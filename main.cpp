#include <iostream>
#include <ctime>
#include <string>
#include <fstream>



/*
* Еще не все успел сделать =(
* 
    Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. Инициализировать
    его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память.
     =) Разбить программу на функции.

    Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
     Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.

    Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов
    в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.

    * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).

    * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы
    слово в указанном пользователем файле (для простоты работаем только с латиницей).
*/

std::string name1, name2;

void pintArray(int* pArr, const int arrSIZE)
{
    std::cout << "Print Array:" << std::endl;
    for (size_t i = 0; i < arrSIZE; i++)
    {
        std::cout << "[ " << i << " ] = " << pArr[i] << std::endl;
    }

}

void pintArray(int** ppArr, const int arrSIZE)
{
    std::cout << "Print Array:" << std::endl;
    for (int a = 0; a < arrSIZE; a++)
    {
        for (int j = 0; j < arrSIZE; j++)
        {
            std::cout << "[ " << ppArr[a][j] << " ]  ";  // Каждый элемент случайному числу от 0 до 9
        }
        std::cout << std::endl;
    }
   

}

void writeFile(std::ofstream & outPot, const std::string fileName, const std::string text)
{
    outPot.open(fileName);
    if (outPot.is_open())
    {
        outPot << text;
        outPot.close();
    }


}

std::string readFile(std::ifstream & fin, const std::string fileName)
{
    std::string result;
    fin.open(fileName);
    if(fin.is_open())
    {
        do
        {
            std::string buf;
            getline(fin, buf);
            result = buf;
        } while (!fin.eof());
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
    fin.close();
    return result;
}

void leesenLoop()
{
    //////////////////Работа с оперативой паматью.//////////////
    std::cout << "Enter value" << std::endl;

    size_t n = 0;
    std::cin >> n;

    // 1. Выделение памяти в куче.
    int* pArr = new int[n];

    if (pArr != nullptr) // Проверяем, что бы указатель не был nullptr(Памяти не достаточно)
    {

        // 2. Работа с масивом
        pArr[0] = 100;
        pArr[1] = pArr[0] * 2;
        pintArray(pArr, n);

        // 3. Освобождение памяти
        delete[] pArr;
        pArr = nullptr;
    }
    else
    {
        std::cerr << "Error! Can not allocate memory!" << std::endl;
    }

    ///////////////////////////////////////////////////////////
    // Выделение памяти на матрицу.

    // 1. Выделение памяти для массива указателей в куче.
    int** ppArr = new (std::nothrow) int* [n];
    for (int i = 0; i < n; i++)
        ppArr[i] = new int[n];

    // 2. Работа с масивом
    ppArr[0][0] = 100;
    ppArr[1][1] = pArr[0] * 2;

    // 3. Освобождение памяти
    for (int i = 0; i < n; i++)
        delete[] ppArr[i];

    delete[] ppArr;
    ppArr = nullptr;

}

void memoryWrite()
{
   const int SIZE = 5;
   int arr[SIZE]{5, 14, 4, 53, 3};

   std::ofstream fout("1.txt"); // Создаем поток записи в файл.

    fout << "My array" << std::endl; // Записиваем в поток.

    for (const auto& element : arr)
    {
        fout << element << std::endl;
    }
    
   fout.close(); // Закрываем поток.

} 

void task1()
{
    /*
        Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. Инициализировать
    его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =)
    Разбить программу на функции.
    */

    std::cout << "Enter range array = ";
    int arrSIZE;
    std::cin >> arrSIZE;
    std::cout << std::endl;

    int* pArr = new int[arrSIZE];

    for (size_t i = 0; i < arrSIZE; i++)
    {
        if (i == 0)
        {
            const int firstIndex = 1;
            pArr[i] = firstIndex;
            continue;
        }
        pArr[i] = pArr[i - 1] * 2;
    }

    pintArray(pArr, arrSIZE);

    delete[] pArr;
    pArr = nullptr;

}

void task2()
{
    /*
         Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
     Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
    */
    std::cout << "Enter range array = ";
    int arrSIZE;
    std::cin >> arrSIZE;
    int** ppArr = new (std::nothrow) int* [arrSIZE];
    for (int i = 0; i < arrSIZE; i++)
        ppArr[i] = new int[arrSIZE];

    for (int a = 0; a < arrSIZE; a++)
    {
        for (int j = 0; j < arrSIZE; j++)
        {
            ppArr[a][j] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
        }
    }

    pintArray(ppArr, arrSIZE);

    // 3. Освобождение памяти
    for (int i = 0; i < arrSIZE; i++)
        delete[] ppArr[i];

    delete[] ppArr;
    ppArr = nullptr;
}

void task3()
{
    /*
        *  Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов
        в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.
    */
    std::cout << "Enter file name 1 - ";
    std::cin >> name1;
    std::cout << std::endl;
    std::cout << "Enter file name 2 - ";
    std::cin >> name2;
    std::cout << std::endl;

    std::ofstream fOut1;
    const std::string text1 = "Hello world, my first program for write file. ";
    writeFile(fOut1, name1, text1);

    std::ofstream fOut2;
    const std::string text2 = "Create second file...";
    writeFile(fOut2, name2, text2);




}

void task4()
{
  /*
    * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
  */
    std::ifstream fIn;
    std::string buf1 = readFile(fIn, name1);
    std::string buf2 = readFile(fIn, name2);

    std::cout << "Enter file name - ";
    std::string myName;
    std::cin >> myName;

    std::string result = buf1 + buf2;
    std::ofstream fOut1;
    writeFile(fOut1, myName, result);
    //writeFile(fOut1, myName, buf2);



}

bool task5()
{
   
    /*
     * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы
    слово в указанном пользователем файле (для простоты работаем только с латиницей).
    */

   std::cout << "Enter seach word - ";
   std::string searchWord;
   std::cin >> searchWord;
  
  
   const std::string fileName = "res";
   std::ifstream file(fileName);

   if (file.is_open())
   {
       std::string line;

       while (!file.eof())
       {
            getline(file, line);
            if(line.find(searchWord) != std::string::npos)
            {
                return true;
            }

       }
   }
   return false;
}

int main()
{
    srand(time(NULL));
    //leesenLoop(); // Примеры с лекции
    //memoryWrite(); // Пример записи массива в txt файл.
    task1();
    task2();
    task3();
    std::cout << "Third file name -> res  !!!" << std::endl;
    task4();
    std::cout << task5() << std::endl;

}
