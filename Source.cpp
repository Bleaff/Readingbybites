#include<fstream>
#include<bitset>
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{// ������ �� ����� . �������� � ����� ����� � ����������� 

	ifstream stream("Test.txt", ios::binary | ios::in);

	bitset<8> bitarray;

	string stringstr, secondstr;


	//���������� ���������� bitset
	while (stream)
	{
		stream >> stringstr;

		for (size_t i = 0; i < stringstr.size(); i++)
		{
			// ������� � ������ �� ������ ������� 
			bitarray = stringstr[i];
			cout << setw(9) << left << "Before: " << bitset <8>(stringstr[i]) << " " << endl;
			//������ ������ ��� 
			bitarray.flip();
			cout << setw(9) << left << "After: " << bitset<8>(bitarray) << ' ' << endl << endl;
			//���������� � secondstr ������������ ��������� ������� 
			secondstr += char(bitarray.to_ulong());
			//������� ������ 
			bitarray.reset();
		}
		//������� ������ 
		stringstr.clear();

		if (stream.eof())break;

	}
	ofstream outstream;
	// ��������� ���� ��� ������ ( ���� ��� ��� , �� ��������� ������������� )
	outstream.open("Test_answer.txt");
	//���������� � ����
	outstream << secondstr;
	//��������� ����
	outstream.close();
	//��������� ���� �� �������� �������� ����������� �������
	stream.close();

	return 0;
}
