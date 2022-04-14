#include <stdio.h>
#include <windows.h>

int bakiye = 500;
int cardsifresi = 4444;
int basamak;

int basamakver(int sayi){
	int basamaksayi;
	while(sayi > 0){ 

        sayi = sayi / 10;
        basamaksayi++;  
    }
	return basamaksayi;
}
void welcome(){
	printf("\t==================\n");
	printf("\tX Bank Hosgeldiniz\n");
	printf("\t==================\n");
}

int bakiyesorgu(int *bakiye){
	printf("\nMevcut bakiye : %d",*bakiye);

}

int cardpassal(){
	int cardpass;
	cardpassalsetup:
	printf("4 Haneli Kart Numaranizi Giriniz: ");
	scanf("%d",&cardpass);
	basamak = basamakver(cardpass);
	while(basamak!=4){
		goto cardpassalsetup;
	}
	return cardpass;
	
}

int cardpasscheck(int cardpass){
	bool check = false;
	if(cardpass == cardsifresi){
		check = true;
	}
	else if(cardpass != cardsifresi){
		check = false;
	}
	return check;
}

void anaislemmenu(){
	printf("\n[1]Nakit islemleri");
	printf("\n[2]Kart islemleri");
	printf("\n[3]Kart iade");
	printf("\n:");
}

int anaislemsec(){
	int islemsec;
	scanf("%d",&islemsec);
	return islemsec;
}

void nakitislemmenu(){
	printf("\n[1]Para cek");
	printf("\n[2]Para yatir");
	printf("\n[3]Bakiye sorgu");
	printf("\n[4]Ana menu");
	printf("\n:");
}

int nakitislemsec(){
	int islemcsec;
	scanf("%d",&islemcsec);
	return islemcsec;
}

int paracek(){
	int cekilecek;
	printf("\t==================\n");
	printf("\tPARA CEKME MENUSU\n");
	printf("\t==================\n");
	printf("Cekilecek tutar giriniz :");
	scanf("%d",&cekilecek);
	if(cekilecek>bakiye){
		printf("\nYetersiz bakiye");
	}
	else if(cekilecek<=bakiye){
		bakiye-=cekilecek;
		printf("\n%d miktarda para cekildi",cekilecek);
		bakiyesorgu(&bakiye);
	}

}

int parayatir(){
	int yatirilacak;
	printf("\t==================\n");
	printf("\tPARA YATIRMA MENUSU\n");
	printf("\t==================\n");
	printf("Yatirilacak tutar giriniz :");
	scanf("%d",&yatirilacak);
	//Sleep(1500);
	bakiye+=yatirilacak;
	printf("\n%d miktarda para yatirildi",yatirilacak);
	bakiyesorgu(&bakiye);
}


void kartislemmenu(){
	printf("\n[1]Kart bilgileri");
	printf("\n[2]Kart sifresi degistir");
	printf("\n[3]Ana menu");
	printf("\n:");
}

int kartislemsec(){
	int islemcsec;
	scanf("%d",&islemcsec);
	return islemcsec;
}

int kartbilgileri(){
	printf("\nAd Soyad : X Talas");
	printf("\nMevcut bakiye : %d",bakiye);
}

int kartsifredegis(){
	int mevcut;
	kartsifredegissetup:
	printf("Mevcut sifre :");
	scanf("%d",&mevcut);  
	basamak = basamakver(mevcut);
	while(basamak!=4){
		goto kartsifredegissetup;
	}
	if(mevcut==cardsifresi){
		yenisifresetup:
		printf("\nYeni sifre :");
		scanf("%d",&cardsifresi);
		basamak = basamakver(cardsifresi);
		while(basamak!=4){
			goto yenisifresetup;
		}
		printf("\nKart sifresi basariyle degistirildi !");
		printf("\nYeni sifre :%d",cardsifresi);
		Sleep(3000);
	}
	else{
		printf("\nMevcut sifre hatali");
	}
}



/*


 //github.com/MrTalas



*/

int main(){
	int cardpass;
	int block=2;
	int anaislem;
	int nakitislem;
	int kartislem;
	bool check;
	setup:
	system("cls");
	welcome();
	cardpass = cardpassal();
	check = cardpasscheck(cardpass);
	if(block==0){
		printf("Kart sifrenizi 3 defa yanlis girdiginiz icin kartiniz bloka olmustur");
		Sleep(1500);
		exit(0);
	}
	if(check==true){
		printf("Kart sifresi dogru !");
		//Sleep(1500);
		anaislemsetup:
		system("cls");
		anaislemmenu();
		anaislem = anaislemsec();
		switch(anaislem){
			case 1: // [1]Nakit islemleri
				nakitsetup:
				//system("cls");
				nakitislemmenu();
				nakitislem = nakitislemsec();
				if(nakitislem==1){ //Para Çek
					paracek();
					goto nakitsetup;
				}
				else if(nakitislem==2){ //Para Yatır
					parayatir();
					goto nakitsetup;
				}
				else if(nakitislem==3){ //Bakiye Sorgu
					bakiyesorgu(&bakiye);
					goto nakitsetup;
				}
				else if(nakitislem==4){ // Ana menuye dön
					goto anaislemsetup;
				}
				else{
					goto nakitsetup;
				}
				break;
			case 2: // [2]Kart islemleri
				kartsetup:
				system("cls");
				kartislemmenu();
				kartislem = kartislemsec();
				if(kartislem==1){ // Kart Bilgileri
					kartbilgileri();
				}
				else if(kartislem==2){ // Kart Şifresi Değiştir
					kartsifredegis();
					goto anaislemsetup;
				}
				else if(kartislem==3){ // Ana menuye dön
					goto anaislemsetup;
				}
				else{
					goto kartsetup;
				}
				break;
			case 3: // [3]Kart iade
				printf("Kartinizi almayi unutmayiniz");
				Sleep(3000);
				break;
			default:
				goto anaislemsetup;
		}
	}
	else{
		block--;
		printf("Kart sifresi yanlis !\n");
		printf("Kalan deneme hakkiniz (%d)",block+1);
		Sleep(1500);
		goto setup;
	}
	return 0;
}
