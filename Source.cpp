#include<fstream>
#include<bitset>
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{// чтение из файла . лежащего в одной папке с приложением 

	ifstream stream("Test.txt", ios::binary | ios::in);

	bitset<8> bitarray;

	string stringstr, secondstr;


	//заполнение котнейнера bitset
	while (stream)
	{
		stream >> stringstr;

		for (size_t i = 0; i < stringstr.size(); i++)
		{
			// передаём в битсет по одному символу 
			bitarray = stringstr[i];
			cout << setw(9) << left << "Before: " << bitset <8>(stringstr[i]) << " " << endl;
			//меняем каждый бит 
			bitarray.flip();
			cout << setw(9) << left << "After: " << bitset<8>(bitarray) << ' ' << endl << endl;
			//записываем в secondstr получившуюся кодировку символа 
			secondstr += char(bitarray.to_ulong());
			//очищаем массив 
			bitarray.reset();
		}
		//очищаем строку 
		stringstr.clear();

		if (stream.eof())break;

	}
	ofstream outstream;
	// открываем файл для записи ( если его нет , он создаёстся автоматически )
	outstream.open("Test_answer.txt");
	//записываем в файл
	outstream << secondstr;
	//закрываем файл
	outstream.close();
	//закрываем файл из которого получили изначальные символы
	stream.close();

	return 0;
}
