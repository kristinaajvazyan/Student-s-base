#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{

  int cdstd, valueS, valueM, sum1 = 0, count1 = 0, AvSc1, cddsp, sum2 = 0, count2 = 0, AvSc2;
    int valueFD2, valueSD2, valueSD3;
    fpos_t ind;
    char sym;

    FILE *f;
    if(!(f = fopen("student.txt", "rt")))    //проверка доступа к файлу
    {
        printf("\nНевозможно открыть файл");
        fclose(f);
        return -1;
    }

    if(!(f = fopen("mark.txt", "rt")))    //проверка доступа к файлу
    {
        printf("\nНевозможно открыть файл");
        fclose(f);
        return -1;
    }

    if(!(f = fopen("StudentInformation.txt", "wt")))    //проверка доступа к файлу
    {
        printf("\nНевозможно открыть файл");
        fclose(f);
        return -1;
    }

    if(!(f = fopen("discipline.txt", "rt")))    //проверка доступа к файлу
    {
        printf("\nНевозможно открыть файл");
        fclose(f);
        return -1;
    }

    if(!(f = fopen("MarkInformation.txt", "wt")))    //проверка доступа к файлу
    {
        printf("\nНевозможно открыть файл");
        fclose(f);
        return -1;
    }
  

  char* trashOut;
  trashOut = (char*)calloc(50, sizeof(char)); //указатель на строку

  int textS;

  char* trashS;
  trashS = (char*)calloc(50, sizeof(char));  //указатель на строку

  char* trashM;
  trashM = (char*)calloc(50, sizeof(char));  //указатель на строку

  char* textM;
  textM = (char*)calloc(50, sizeof(char));  //указатель на строку
    
    int d1, d2, m1, m2, y1, y2;


    printf("Введите код студента: \n");
    scanf("%d", &cdstd);
//    printf("Обозначьте начало сессии: \n");
//    scanf("%d.%d.%d", &d1, &m1, &y1);
//    printf("Обозначьте конец сессии: \n");
//    scanf("%d.%d.%d", &d2, &m2, &y2);
    
    fopen("student.txt", "rt");

    rewind(f);
//    fgets(trashS, 250, f);       //Пропускаем шапки двух файлов
    fscanf(f, "%c", &sym);
    ind = ftell(f);
    
//    fgets(trashM, 250, f);
//    fgets(trashM, 250, f);
    
  while (!feof(f))
  {
    fscanf(f, "%d", &textS);               //Код студента
      fgets(trashS, 250, f);   //Вся строка
    if (textS == cdstd)        //Если код подходит, то выводим ФИО и код студента
    {
        puts(trashS);
        fputs(trashS, f);
    }
  }
    
    while (!feof(f))
      {
          fputs(textM, f);
        fgets(trashM, 250, f);                   //Вся строка
        valueM = atoi(textM);
        if (valueM == cdstd)                        //Если код совпадает
        {                      //Делим строку на 4 части
          char* part1 = strtok(trashM, "|");      //Код студента
          char* part2 = strtok(NULL, "|");        //Код дисциплины
          char* part3 = strtok(NULL, "|");        //Оценка из файла
          char* part4 = strtok(NULL, "|");        //Дата из файла
                              //Делим дату из файла на 3 части
          char* TinyPart1 = strtok(part4, ".");   //День из Mark.txt
          char* TinyPart2 = strtok(NULL, ".");    // Месяц из Mark.txt
          char* TinyPart3 = strtok(NULL, ".");    //Год из Mark.txt

          int valueMD1 = atoi(TinyPart1);         //int день из файла
          int valueMD2 = atoi(TinyPart2);         //int месяц из файла
          int valueMD3 = atoi(TinyPart3);         //int год из файла

          int valueMO = atoi(part3);              //int оценка из файла
    

          if (valueSD3 == valueMD3)               //!!!Проверка на совпадение периода!!!
          {
            if (valueSD2 >= valueMD2 && valueSD2 <= valueFD2)
            {
              sum1 += valueMO;                 //Суммируем оценки
              count1++;
            }
          }
        }
      }
      AvSc1 = sum1 / count1;                            //Средний балл
    printf("Средний балл: %d", AvSc1);
    fprintf(f, "%d", AvSc1);

    printf("Введите код дисциплины: ");
    scanf("%d", &cddsp);
    printf("Обозначьте начало сессии и конец: \n");
    printf("Обозначьте начало сессии: \n");
    scanf("%d.%d.%d", &d1, &m1, &y1);
    printf("Обозначьте конец сессии: \n");
    scanf("%d.%d.%d", &d2, &m2, &y2);

      fgets(trashM, 250, f);
      fgets(trashM, 250, f);

      while (!feof(f))
      {
        fgets(trashM, 250, f);
        //Делим строку на 4 части
        char* part1 = strtok(trashM, "|");      //Код студента
        char* part2 = strtok(NULL, "|");        //Код дисциплины
        char* part3 = strtok(NULL, "|");        //Оценка из файла
        char* part4 = strtok(NULL, "|");        //Дата из файла

        int valueCdM2 = atoi(part2);
        int valueCdM3 = atoi(part3);

        //Делим дату из файла на 3 части
        char* TinyPart1 = strtok(part4, ".");   //День из Mark.txt
        char* TinyPart2 = strtok(NULL, ".");    //Месяц из Mark.txt
        char* TinyPart3 = strtok(NULL, ".");    //Год из Mark.txt

        int valueMD1 = atoi(TinyPart1);         //int день из файла
        int valueMD2 = atoi(TinyPart2);         //int месяц из файла
        int valueMD3 = atoi(TinyPart3);         //int год из файла

        if (valueCdM2 == cddsp)            //Совпадение введенного кода дисциплины и файлового
        {

          if (valueSD3 == valueMD3)           //!!!Проверка на совпадение периода!!!
          {
            if (valueSD2 >= valueMD2 && valueSD2 <= valueFD2)
            {
              sum2 += valueCdM3;          //Суммируем оценки
              count2++;
            }
          }
        }
      }

      fgets(trashOut, 250, f);
      fgets(trashOut, 250, f);

      while (!feof(f))
      {
          puts(trashOut);
        fgets(trashOut, 250, f);
        int valueCdD = atoi(trashOut);              //int Код исциплины
        if (valueCdD == cddsp)
            fputs(trashOut, f);  //Совпадение введенного и файлового КодаДсцп
      }

      AvSc2 =sum2/count2;
    printf("%d", AvSc2);
    fprintf(f, AvSc2, "%d");
    }
