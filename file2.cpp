#include <iostream>
#include <fstream>

using namespace std;

bool WriteFile(string text, string path);
bool ReadFile(string *text, string path);

int main()
{
    bool status;
    status = WriteFile("Ola Mundo, hoje fez um calorao do caramba !\n", "f1.txt");
    if(status == false)
        cout << "Error to write file" << endl;

    status = WriteFile("Acho que a prova de calculo vai dar ruim !\n", "f2.txt");
    if(status == false)
        cout << "Error to write file" << endl;

    string text;
    status = ReadFile(&text,"f3.txt");
    if(status == false)
        cout << "Error to read file" << endl;
    cout << text << endl;

    return 0;
}

bool ReadFile(string *text, string path)
{
    text->clear();   //*text = "";

    ifstream fr(path);
    if(fr.good())
    {
        //le uma unica linha de um arquivo de texto
        /*string tmp;
        getline(fr, tmp);
        *text = tmp;
        fr.close();*/

        string tmp;
        while(getline(fr, tmp))
        {
            *text += tmp;
            //text->append(tmp);
        }
        fr.close();
        return true;
    }
    else
        return false;
}


bool WriteFile(string text, string path)
{
    ofstream fw(path);
    if(fw.good())
    {
        fw << text;
        fw.close();
        return true;
    }
    else
        return false;
}