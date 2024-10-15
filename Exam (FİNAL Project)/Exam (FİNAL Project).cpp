#include <iostream>

using namespace std;

class sual {
public:
	char sualmetni[100];
	char cavab[100];

	void suali_qoy(const char* sualmetni_giris, const char* cavab_giris) {
		int i = 0;
		while (sualmetni_giris[i] != '\0' && i < 100)
		{
			sualmetni[i] = sualmetni_giris[i];
			i++;
		}
		sualmetni[i] = '\0';

		i = 0;
		while (cavab_giris[i] != '\0' && i < 100) {
			cavab[i] = cavab_giris[i];
			i++;
		}
		cavab[i] = '\0';
	}
};

class quiz {
public:
	char basliq[50];
	sual suallar[10];
	int sual_sayi;

	quiz()
	{
		sual_sayi = 0;
	}

	void Basligi_qoy(const char* basliq_giris) {
		int i = 0;
		while (basliq_giris[i] != '\0' && i < 50) {
			basliq[i] = basliq_giris[i];
			i++;
		}
		basliq[i] = '\0';
	}

	void Sual_elave_et(const char* sualmetni_giris, const char* cavab_giris) {
		if (sual_sayi < 10) {
			suallar[sual_sayi].suali_qoy(sualmetni_giris, cavab_giris);
			sual_sayi++;
		}
		else {
			cout << "Maksimum sual sayina catdi!" << endl;
		}
	}

	void Quizi_goruntule() const {
		cout << "Quiz: " << basliq << endl;
		for (int i = 0; i < sual_sayi; i++) {
			cout << i + 1 << ". " << suallar[i].sualmetni << endl;
			cout << "Cavab: " << suallar[i].cavab << endl;
		}
	}
};

quiz quizler[10];
int quiz_sayi = 0;

void Quiz_yarat() {
	if (quiz_sayi >= 10) {
		cout << "Quiz sayi maksimuma çatdi!" << endl;
		return;
	}

	quiz yeni_quiz;
	char basliq[50];
	cout << "Yeni quiz adini daxil edin: ";
	cin.ignore();
	cin.getline(basliq, 50);
	yeni_quiz.Basligi_qoy(basliq);

	char dahaSual;
	do
	{
		char sualmetni[100];
		char cavab[100];

		cout << "Yeni sual daxil edin: ";
		cin.getline(sualmetni, 100);
		cout << "Cavabi daxil edin: ";
		cin.getline(cavab, 100);

		yeni_quiz.Sual_elave_et(sualmetni, cavab);

		cout << "Daha sual elave etmek isteyirsiniz? (he/yox): ";
		cin >> dahaSual;
		cin.ignore();
	} while (dahaSual == 'He');

	quizler[quiz_sayi] = yeni_quiz;
	quiz_sayi++;
	cout << "Yeni quiz yaradildi ve yadda saxlanildi!" << endl;
}

void Quizleri_goruntule() {
	if (quiz_sayi == 0) {
		cout << "Hazirda hec bir quiz yoxdur!" << endl;
		return;
	}

	for (int i = 0; i < quiz_sayi; i++) {
		cout << i + 1 << ". " << quizler[i].basliq << endl;
	}

	int secim;
	cout << "Görmek istediyiniz quizin nömresini daxil edin: ";
	cin >> secim;

	if (secim < 1 || secim > quiz_sayi) {
		cout << "Yanlis secim!" << endl;
		return;
	}

	quizler[secim - 1].Quizi_goruntule();
}

void Admin_menu() {
	int secim;
	do {
		cout << "\nAdmin Menyusu\n";
		cout << "1. Yeni Quiz yaratmaq\n";
		cout << "2. Quizlere baxmaq\n";
		cout << "3. Cixis etmek\n";
		cout << "Seciminizi edin: ";
		cin >> secim;

		switch (secim) {
		case 1:
			Quiz_yarat();
			break;
		case 2:
			Quizleri_goruntule();
			break;
		case 3:
			cout << "Cixis edilir...\n";
			break;
		default:
			cout << "Yanlis secim! Yeniden cehd edin." << endl;
		}
	} while (secim != 3);
}

int main() {
	Admin_menu();
	return 0;
}

