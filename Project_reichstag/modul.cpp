#include "modul.h"

void create_file(string filename, jk& list)
{
    ofstream file(filename, ios::binary);
    int n;
   ofstream fileOut("temp.txt");
    cout << "������ ������� ��������: ";
    cin >> n; 
    fileOut<< "������ ������� ��������: "<<n<<endl;
    
       
        for (int i = 0; i < n; ++i) {
            fileOut << "����� #" << i + 1 << endl;
            cout << "����� #" << i + 1 << endl; 
            cout << " ����� ������: ";  cin>>list.number; cin.ignore();
            fileOut << " ����� ������: "<<list.number<<endl;
            cout << "��������� �������: "; cin.getline(list.first_station, 50);
            fileOut << "��������� �������: "<<list.first_station<<endl;
            cout << "ʳ����� �������: "; cin.getline(list.last_station, 50);
            fileOut << "ʳ����� �������: "<<list.last_station<<endl;
            cout << "��� �����������: "; cin>>list.time_first; 
            fileOut << "��� �����������: " << list.time_first<<endl;
            cout << "��� ��������: "; cin >> list.time_last;
            fileOut << "��� ��������: "<<list.time_last<<endl;
            cout << "³������: "; cin >> list.distance;
            fileOut << "³������: "<<list.distance<<endl;
            file.write((char*)&list, sizeof list);
        }
        fileOut.close();
    file.close();

}
void print_file(const jk& list) {
   ofstream fileOut("temp.txt",ios::app);
    fileOut<< "| " << setw(4) << left << list.number << " | "
        << setw(18) << left << list.first_station << " | "
        << setw(20) << left << list.last_station << " | "
        << setw(17) << left << list.time_first << " | "
        << setw(14) << left << list.time_last << " | "
        << setw(9) << left << list.distance << " |" << endl;
    cout << "| " << setw(4) << left << list.number << " | "
        << setw(18) << left << list.first_station << " | "
        << setw(20) << left << list.last_station << " | "
        << setw(17) << left << list.time_first << " | "
        << setw(14) << left << list.time_last << " | "
        << setw(9) << left << list.distance << " |" << endl;
    fileOut.close();
}

void add_file(string filename, jk& list) {
   ofstream fileOut("temp.txt",ios::app);
    ofstream file(filename, ios::binary | ios::app);
    int n;
    cout << "������ ������� ��������: ";
    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i) {
        fileOut << "����� #" << i + 1 << endl;
        cout << "����� #" << i + 1 << endl;
        cout << " ����� ������: ";  cin >> list.number; cin.ignore();
        fileOut << " ����� ������: " << list.number << endl;
        cout << "��������� �������: "; cin.getline(list.first_station, 50);
        fileOut << "��������� �������: " << list.first_station << endl;
        cout << "ʳ����� �������: "; cin.getline(list.last_station, 50);
        fileOut << "ʳ����� �������: " << list.last_station << endl;
        cout << "��� �����������: "; cin >> list.time_first;
        fileOut << "��� �����������: " << list.time_first << endl;
        cout << "��� ��������: "; cin >> list.time_last;
        fileOut << "��� ��������: " << list.time_last << endl;
        cout << "³������: "; cin >> list.distance;
        fileOut << "³������: " << list.distance << endl;
        file.write((char*)&list, sizeof list);
    }
    file.close();
    fileOut.close();
}
void read_file(string filename, jk& list) {
    ifstream file(filename, ios::binary);
   ofstream fileOut("temp.txt",ios::app);
    file.clear();
    file.seekg(0);
    if (!file) {
        fileOut << "������� �������� " << filename << endl;
        cout << "������� �������� " << filename << endl;
    }
    fileOut << "| �    | ��������� �������  | ʳ����� �������      | ��� �����������  | ��� ��������   | ³������ |" << endl;
    fileOut << "+------+--------------------+----------------------+-------------------+----------------+---------+" << endl;
    cout << "| �    | ��������� �������  | ʳ����� �������      | ��� �����������  | ��� ��������   | ³������ |" << endl;
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
    while (file.read((char*)&list, sizeof list)) {
        if (file.eof()) {
            fileOut << "������� ��� ������ �����." << endl;
            cout << "������� ��� ������ �����." << endl;
            break;
        }
        print_file(list);
    }
    fileOut<< "+------+-------------------+---------------------+-------------------+----------------+-----------+" << endl;
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
    file.close();
    fileOut.close();
}
void vvedenyaTimeVidp(string filename, jk& list)
{
   ofstream fileOut("temp.txt",ios::app);

    ifstream f(filename, ios::binary);

    while (f.read((char*)&list, sizeof list))
    {
        double time; time = list.time_last - list.time_first;
        double speed; speed = list.distance / (time);
        if ((list.time_last - list.time_first) == 0) {
            speed = 0;
        }
        fileOut<< list.number << ">> " << speed << " km/h" << endl;
        cout <<list.number<<">> " << speed <<" km/h"<< endl;
    }
    f.close();
    fileOut.close();
}
void searchStation3(string path,jk& list)
{

   ofstream fileOut("temp.txt",ios::app);
    ifstream fileIn(path, ios::binary);
    bool find= false;
  fileOut<< "������ �����, ������� �������� ���� ������� �� �������� �����������:" << endl;
  fileOut << "| �    | ��������� ������� | ʳ����� �������     | ��� ����������� | ��� ��������  | ³������ |" << endl;
  fileOut << "+------+-------------------+---------------------+-------------------+----------------+-----------+" << endl;

    cout << "������ �����, ������� �������� ���� ������� �� �������� �����������:" << endl;
    cout << "| �    | ��������� �������  | ʳ����� �������      | ��� �����������  | ��� ��������   | ³������ |" << endl;
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
    fileOut.close();

    while (fileIn.read((char*)&list, sizeof list))
    {
        if (strcmp(list.first_station, list.last_station) == 0)
        {
            find = true;
  
            print_file(list);
           
        }
      
    }
    if (!find) cout << "\n�� �������� ����� �����!";
    fileIn.close();
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
}
void searchStation1(string path, jk& list)
{
    ofstream fileOut("temp.txt", ios::app);
    
    ifstream fileIn(path, ios::binary);

    char input_station[50];
    
    cout << "������ ������ ������� ��� ������: ";
    cin >> input_station;
    fileOut << "������ ������ ������� ��� ������: "<<input_station;
    cout << "������ �����, �� ��� ������� ������ �� �������� ��������:" << endl;
    cout << "| �    | ��������� �������  | ʳ����� �������      | ��� �����������  | ��� ��������   | ³������ |" << endl;
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
    fileOut << "������ �����, �� ��� ������� ������ �� �������� ��������:" << endl;
    fileOut << "| �    | ��������� ������� | ʳ����� �������     | ��� ����������� | ��� ��������  | ³������ |" << endl;
    fileOut << "+------+-------------------+---------------------+-------------------+----------------+-----------+" << endl;
    fileOut.close();
    while (fileIn.read((char*)&list, sizeof list))
    {
        if (strcmp(list.last_station, input_station) == 0)
        {

            print_file(list);
        }
    }
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
    fileIn.close();
}
void searchStation2(string path, jk& list)
{
    ofstream fileOut("temp.txt",ios::app);
    jk jk;
    ifstream fileIn(path, ios::binary);

    char input_station[50];
    cout << "������ ������� ��� ������: ";
    cin >> input_station;
    fileOut << "������ ������� ��� ������: " << input_station;
    cout << "������ �����, �� ��� ������� ������ �� �������� ��������:" << endl;
    while (fileIn.read((char*)&jk, sizeof jk))
    {
        if (strcmp(jk.first_station, input_station) == 0)
        {
            cout << jk.number << endl;
            fileOut<< jk.number << endl;
        }
    }

    fileIn.close();
    fileOut.close();
}
bool compare(const jk& a, const jk& b) {
    return strcmp(a.first_station, b.first_station) < 0;
}
void swap(jk& a, jk& b) {
    jk temp = a;
    a = b;
    b = temp;
}
void sortinfile(string filename) {
    jk list[50];
    ifstream fileIn(filename, ios::binary);
    int count = 0;
    while (fileIn.read(reinterpret_cast<char*>(&list[count]), sizeof(jk))) {
        count++;
    }
    fileIn.close();

    // ���������� ������ �� first_station
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (compare(list[j], list[i])) {
                swap(list[i], list[j]);
            }
        }
    }
    ofstream fileOut("sorted_" + filename + ".txt");
    for (int i = 0; i < count; ++i) {
        fileOut << "�����: " << list[i].number << endl;
        fileOut << "��������� �������: " << list[i].first_station << endl;
        fileOut << "ʳ����� �������: " << list[i].last_station << endl;
        fileOut << "��� �����������: " << list[i].time_first << endl;
        fileOut << "��� ��������: " << list[i].time_last << endl;
        fileOut << "³������: " << list[i].distance << endl;
        fileOut << "---------------------------" << endl;
    }
    cout << "������ ������������ ������!";
    fileOut.close();
}
void printDuplicates(int arr[], int size) {
    bool hasDuplicates = false;

    cout << "��������� � ����� �����:" << endl;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                hasDuplicates = true;
            }
        }
    }

    if (!hasDuplicates) {
        cout << "�������� �� ��������";
    }
    cout << endl;
}

void printTrainTable(jk arr[], int size) {
    cout << "| �    | ��������� �������  | ʳ����� �������      | ��� �����������  | ��� ��������   | ³������ |" << endl;
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
    for (int i = 0; i < size; ++i) {
        print_file(arr[i]);
    }
    cout << "+------+--------------------+----------------------+-------------------+----------------+----------+" << endl;
}

void trainsodnochasno(string filename) {
    jk list;
    ifstream fileIn(filename, ios::binary);
    char input_station[50];
    jk result[50];
    int n = 0;
    double last_arrival_time = 0;
    cout << "������ ������� ��� ������: ";
    cin >> input_station;

    cout << "�����, � ���� ��� �������� ���������:" << endl;
    while (fileIn.read((char*)&list, sizeof list)) {
        if (strcmp(list.last_station, input_station) == 0) {
            if (list.time_last == last_arrival_time) {
                result[n] = list;
                n++;
            }
            else {
                if (n > 1) {
                    printTrainTable(result, n);
                    cout << endl;
                }
                n = 0;
                last_arrival_time = list.time_last;
                result[n] = list;
                n++;
            }
        }
    }

    if (n > 1) {
        printTrainTable(result, n);
    }
    else {
        cout << "����� �� ���� �������� � ��������� ����� �������� �� ��������." << endl;
    }

    fileIn.close();
}