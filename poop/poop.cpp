// poop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

void duplicate(std::string word);
void transpon(std::string word, std::string word2);
void space(std:: string word);
void polinome(std::string word);
void mode(std::string word, std::string word2);
void compression(std::string word);
void zero(int **p_array, int row, int column);
void debet(int price, int begin, int add);

int main()
{
    int choice;
    std::cout << "enter your choice\n";
    std::cout << "1. chek duplicate\n";
    std::cout << "2. chek transponate\n";
    std::cout << "3. change space\n";
    std::cout << "4. chek polinome\n";
    std::cout << "5. chek modding\n";
    std::cout << "6. compression\n";
    std::cout << "7. destroy zero\n";
    std::cout << "8. debet\n";
    std::cout << "9. exit\n";
    std::cin >> choice;
    std::string word;
    std::string word2;
    int price;
    int begin;
    int add;
    int **p_array;
    int row;
    int column;
    while (choice != 9) {
        switch (choice) {
        case 1:
            std::cout << "enter word\n";
            std::cin.ignore(32000, '\n');
            std::getline(std::cin, word);
            duplicate(word);
            break;
        case 2:
            std::cout << "enter two word\n";
            std::cin.ignore(32000, '\n');
            std::getline(std::cin, word);
            std::getline(std::cin, word2);
            transpon(word, word2);
            break;
        case 3:
            std::cout << "enter word\n";
            std::cin.ignore(32000, '\n');
            std::getline(std::cin, word);
            space(word);
            break;
        case 4:
            std::cout << "enter word\n";
            std::cin.ignore(32000, '\n');
            std::getline(std::cin, word);
            polinome(word);
            break;
        case 5:
            std::cout << "enter two word\n";
            std::cin.ignore(32000, '\n');
            std::getline(std::cin, word);
            std::getline(std::cin, word2);
            mode(word, word2);
            break;
        case 6:
            std::cout << "enter word\n";
            std::cin.ignore(32000, '\n');
            std::getline(std::cin, word);
            compression(word);
            break;
        case 7:
            std::cout << "enter count row\n";
            std::cin >> row;
            std::cout << "enter count colums\n";
            std::wcin >> column;
            p_array = new int* [row];
            for (int i = 0; i < row; i++) {
                p_array[i] = new int[column];
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    std::cout << "enter [" << i << "] [" << j << "] \n";
                    std::cin >> p_array[i][j];
                }
            }
            zero(p_array, row, column);
            break;
        case 8:
            std::cout << "enter price\n";
            std::cin >> price;
            std::cout << "enter begin\n";
            std::cin >> begin;
            std::cout << "enter add\n";
            std::cin >> add;
            debet(price, begin, add);
        case 9:
            choice = 9;
            break;
        default:
            choice = 9;
            break;
        }
        std::cout << "enter your choice\n";
        std::cout << "1.chek duplicate\n";
        std::cout << "2. chek transponate\n";
        std::cout << "3.change space\n";
        std::cout << "4. chek polinome\n";
        std::cout << "5. chek modding\n";
        std::cout << "6. compression\n";
        std::cout << "7. destroy zero\n";
        std::cout << "8. debet\n";
        std::cout << "9. exit\n";
        std::cin >> choice;
    }
}

void duplicate(std::string word) {
    bool err = true;
    int begin = 0;
    int counter = 0;
    int i = 0;
    while (word[i]) {
        counter++;
        i++;
    }
    while (begin < counter && err) {
        int count = 0;
        int beginplus = 1;
        while (beginplus < counter && err) {
            if (word[begin] == word[beginplus]) {
                count++;
            }
            if (count >= 1) {
                std::cout << word[begin] << " - retryed\n";
                err = false;
            }
            beginplus++;
        }
        begin++;
    }
    if (err) {
        std::cout << "retryed not detected\n";
    }
}

void transpon(std::string word, std::string word2) {
    int counter = 0;
    int counter2 = 0;
    int i = 0;
    int count = 0;
    while (word[i]) {
        counter++;
        i++;
    }
    i = 0;
    while (word2[i]) {
        counter2++;
        i++;
    }
    char* p_arr = new char[counter];
    if (counter == counter2) {
        for (int i = 0; i < counter; i++) {
            bool err = true;
            for (int j = 0; j < counter2; j++) {
                for (int g = 0; g < counter; g++) {
                    if (p_arr[g] == word[i]) {
                        err = false;
                    }
                }
                if (word[i] == word2[j] && err ) {
                    count++;
                }
            }
            p_arr[i] = word[i];
        }
    }
    std::cout << count << " " << counter << std::endl;
    if (count == counter) {
        std::cout << "\nword is transponed\n";
    }
    else std::cout << "\nword is not transponed\n";
}

void space(std::string word) {
    
    std::string wordconc = "";
    int counter = 0;
    int i = 0;
    while (word[i]) {
        counter++;
        i++;
    }
    for (int i = 0; i < counter; i++) {
        if (word[i] != ' ') {
            wordconc += word[i];
        }
        else wordconc += "%20";
    }
    std::cout << wordconc << std::endl;
}

void polinome(std::string word) {
    int counter = 0;
    int i = 0;
    bool err = true;
    int cocount = 0;
    char* p_arr = new char[counter];
    bool chek = true;
    while (word[i]) {
        counter++;
        i++;
    }
    i = 0;
    while (i < counter && err) {
        int j = 0;
        int count = 0;
        while (j<counter && err) {
            int g = 0;
            while (g < counter) {
                if (p_arr[g] == word[i]) {
                    chek = false;
                }
                g++;
            }
            if (word[i] == word[j] && chek) {
                count++;
            }
            j++;
        }
        p_arr[i] = word[i];
        chek = true;
        if (count > 2) {
            err = false;
        }
        else if(count == 2) {
            cocount++;
        }
        i++;
    }
    if (cocount == (counter / 2)) {
        std::cout << "string is polinome\n";
    }
    else std::cout << "string is not polinome\n";
}

void mode(std::string word, std::string word2) {
    int counter = 0;
    int counter2 = 0;
    int i = 0;
    int j = 0;
    bool err = true;
    bool chek = true;
    int count = 0;
    while (word[i]) {
        counter++;
        i++;
    }
    while (word2[j]) {
        counter2++;
        j++;
    }
    if (abs(counter - counter2) == 1 || counter == counter2) {
        if (counter > counter2) {
            counter = counter2;
        }
        i = 0;
        char* p_arr = new char[counter];
        while (i < counter && err) {
            int j = 0;
            while (j < counter && err) {
                int g = 0;
                while (g < counter) {
                    if (p_arr[g] == word[i]) {
                        chek = false;
                    }
                    g++;
                }
                if (word[i] == word2[j] && chek) {
                    count++;
                }
                j++;
            }
            p_arr[i] = word[i];
            chek = true;
            i++;
        }
        if (count == counter) {
            std::cout << "word is modding\n";
        }
        else std::cout << "word is not modding\n";
    }
    else std::cout << "word is not modding\n";
}

void compression(std::string word) {
    int i = 0;
    int counter = 0;
    int counter2 = 0;
    int count = 0;
    std::string wordcom="";
    while (word[i]) {
        counter++;
        i++;
    }
    for (int i = 1; i < counter+1; i++) {
        if (word[i-1] == word[i]) {
            count++;
        }
        else {
            count++;
            wordcom += word[i-1] + std::to_string(count);
            count = 0;
        }
    }
    i = 0;
    while (wordcom[i]) {
        counter2++;
        i++;
    }
    if (counter > counter2) {
        std::cout << wordcom << std::endl;
    } else std::cout << word << std::endl;
}

void zero(int **p_array, int row, int column) {
    int count = 0;
    int *p_row = new int[row];
    int *p_col = new int[column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (p_array[i][j] == 0) {
                p_row[count] = i;
                p_col[count] = j;
                count++;
            }
        }
        
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            for (int g = 0; g < row; g++) {
                p_array[g][p_col[j]] = 0;
            }
            for (int m = 0; m < column; m++) {
                p_array[p_row[i]][m] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << p_array[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}

void debet(int price, int begin, int add) {
    int count = 0;
    while (price > begin) {
        price -= begin;
        begin += add;
        count++;
    }
    std::cout << "debet price = " << price << "\n" << "debet sum = " << begin << "\n" << "count = "<<count<< std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
