#include <string>
#include <iostream>

using namespace std;

class Stack
{
public:

    int size;
    int* arr;
    int el_count = 0;
    int top_left_index;
    int top_right_index;

    Stack(int Size)
    {
        size = Size;
        top_left_index = -1;
        top_right_index = size;

        arr = new int [size]; 

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    ~Stack()
    {
        delete[] arr;
    }

    int GetTopLeft()
    {
        return top_left_index;
    }
    int GetTopRight()
    {
        return top_right_index;
    }
    int GetSize()
    {
        return size;
    }
    int GetElementCount()
    {
        return el_count;
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {  
            cout << arr[i] << '\t';
        }
    }

    void PushLeft(int value)
    {
        top_left_index++;
        arr[top_left_index] = value;
        el_count++;
    }
    void PushRight(int value)
    {
        top_right_index--;
        arr[top_right_index] = value;
        el_count++;
    }

    void PopLeft()
    {
        if (top_left_index == -1)
            return;
        else
        {
            arr[top_left_index] = 0;
            top_left_index--;
            el_count--;
        }
    }
    void PopRight()
    {
        if (top_right_index == size)
            return;
        else
        {
            arr[top_right_index] = 0;
            top_right_index++;
            el_count--;
        }
    }
};    

int main()
{
    setlocale(LC_ALL, "Russian");

    int size = 0;
    int operation;
    int value;
    int top_left;
    int top_right;
    int mem_left;
    int el_count;
    int buf = 0;
    int ad[100];

    cout << "Размер стека: ";
    cin >> size;
    system("cls");

    if (size <= 0)
    {
        cout << "ОШИБКА" << endl;
        return 0;
    }

    Stack stack(size);
  
    do
    {
        cout << "\n"; 
        stack.Print();
        cout << "\n";

        size = stack.GetSize();
        top_left = stack.GetTopLeft();
        top_right = stack.GetTopRight();
        el_count = stack.GetElementCount();

        mem_left = (size - el_count) * 4;

        for (int i = 0; i < size; i++)
        {
            if (i == top_left || i == top_right)
                cout << "/\t";
            else
                cout << "\t";
        }

        cout << endl;

        for (int i = 0; i < size; i++)
        {
            if (i == top_left)
                cout << "top left ";
            else if (i == top_right)
                cout << "top right";
            else
                cout << "\t";
        }

        cout << "\n\nОсталось байт памяти: " << mem_left;

        cout << "\n\nСписок команд:\n1) Добавить в левый стек\n2) Добавить в правый стек\n3) Взять из левого стека\n4) Взять из правого стека\n5) Файл\n6) Выход" << endl;
        cin >> operation;

        switch (operation)
        {
        case(1):
            if (mem_left > 0)
            {
                cout << "\nВведите значение: ";
                cin >> value;
                stack.PushLeft(value);
                system("cls");
                break;
            }
            else
            {
                system("cls");
                cout << "!ОШИБКА НЕДОСТАТОЧНО МЕСТА!" << endl;
                break;
            }
        case(2):
            if (mem_left > 0)
            {
                cout << "\nВведите значение: ";
                cin >> value;
                stack.PushRight(value);
                system("cls");
                break;
            }
            else
            {
                system("cls");
                cout << "!ОШИБКА НЕДОСТАТОЧНО МЕСТА!" << endl;
                break;
            }
        case(3):
            stack.PopLeft();
            system("cls");
            break;
        case(4):
            stack.PopRight();
            system("cls");
            break;
        case(5):

            FILE* f;

            fopen_s(&f, "text.txt", "r");
            fscanf_s(f, "%d", &size);
            for (int i = 0; i < size; i++)
            {
                fscanf_s(f, "%d", &buf);
                ad[i] = buf;
            }
            fclose(f);
            for (int i = size - 1; i >= 0; i--)
                stack.PushLeft(ad[i]);
            system("cls");
            break;
            
        default:
            system("cls");
            break;
        }
    } while (operation != 6);

    return 0;
}