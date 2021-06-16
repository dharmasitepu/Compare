#include<stdio.h>
#include<string.h>
#include<stdbool.h>

FILE *data;
FILE *isi_data;
int ada=0;
void adminmenu();void registrasi(); void login(); void usermenu(); void daftarpasien(); void pilihjadwal();void login();
void loginpasien();void loginadmin();void inputjadwal();void inputvaksin(); void find(); void formulir();
int loginadminmenu, n, i, p, luser;
bool ceknampes(char nampes[100]);
struct {
	int kuotavaksin;
	char nama[100], username[100],pass[100],tanggal[100], jenisvaksin[100], lok[100], user[100], pw[100];
	char usernamea[100],passa[50], cari1[100], cari2[100], status[100], jadwal[100];
	
	}logina, a, daftar, temp[100], temp2;
struct{
	char tempat[100], jenis[100], name[100], umur[100], alamat[100], nik[100], gender[100];
}datay;	
void main()
{
	ulang:
	system("cls");
	puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	puts("1. Login Admin");
	puts("2. Registrasi");
	puts("3. Login Pasien ");
	puts("4. Exit");
	printf("\n\nPilih Menu : "); scanf("%d",&p);
	fflush(stdin);
	switch(p)
	{
	case 1:
		loginadmin();
		break;
	case 2:
		registrasi();
		break;
	case 3:
		loginpasien();
		break;
	case 4:
		printf("Terima kasih, Selamat Datang Kembali\n");		
		break;	
	}
}

void loginadmin()
{
	system("cls");
			puts("\t\t\t================================");
			puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
			puts("\t\t\t================================");
			puts("\t\t\t\t Login Admin\n"); 
			printf("username : ");fflush(stdin);gets(logina.usernamea);
			printf("password : ");fflush(stdin);gets(logina.passa);
				if(strcmp(logina.usernamea,"admin")==0&&strcmp(logina.passa,"admin")==0)
				{
					system("cls");adminmenu();
				}
				else{
					system("cls");
				}
		}
	
void adminmenu(){
	system ("cls");
	puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	puts("\t\t\t\t Selamat Datang Admin\n"); 
	puts("1. Input Jadwal");
	puts("2. Daftar Pasien");
	puts("3. Exit");
	printf("Pilihan : "); scanf("%d",&loginadminmenu);
	switch(loginadminmenu)
	{
	case 1:{
		inputjadwal();
		break;
	}
	case 2:{
		daftarpasien();
		break;
	}
	case 3:{
		main();
		break;
	}
	default :printf ("Error!");
}
}

void inputjadwal(){
	system ("cls");
	char tanggal[100], jenisvaksin[100], lok[100];
	int kuotavaksin, n, g;
	FILE*jadwal;
	jadwal=fopen("List tanggal.dat","ab+");
	printf("Banyak jadwal : "); scanf("%d",&g); getchar();
	for(i=1;i<=g;i++){
	printf("%d. Tanggal\t: ",i);gets(a.tanggal); fflush(stdin);
	printf("Jenis Vaksin\t: ");gets(a.jenisvaksin); fflush(stdin);
	printf("Tempat\t\t: ");gets(a.lok); fflush(stdin);
	printf("Kuota\t\t: ");scanf("%d", &a.kuotavaksin); fflush(stdin);
	fwrite(&a, sizeof (a), 1, jadwal);
	}fclose(jadwal); 
	system("pause");
	adminmenu();
}

void daftarpasien(){
	system ("cls");
	int i=1,n;
	FILE*list; 
	list=fopen("akun.dat","rb");
	puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	printf("Daftar Pasien:\n");
	while(fread(&daftar,sizeof(daftar),1,list)==1){
		printf("%d. %s\n",i,daftar.nama);
		i++;
		}
	fclose(list); 
	system("pause");adminmenu();
}

void registrasi(){
	FILE *regis;
    system("cls");
 	puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	printf("\t\t\t\t Silahkan Regis \n");
    regis=fopen("akun.dat","ab");
 {
	printf("nama\t\t: ");fflush(stdin);
    gets(daftar.nama);
	printf("username\t: ");fflush(stdin);
    gets(daftar.username);
  	printf("password\t: ");
    gets(daftar.pass);
    fwrite(&daftar, sizeof(daftar),1, regis);
 }
    fclose(regis); 
	printf("REGISTRASI BERHASIL\n");system("pause");
    main();
}

void loginpasien(){
	char user[100], pw[100];
	FILE *in;
    system("cls");
    puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	printf("\t\t\t\t Silahkan Login \n");
 	printf("Username : ");fflush(stdin); gets(user);
    printf("\nPassword : ");fflush(stdin); gets(pw);
    in=fopen("akun.dat","rb");
    while(fread(&daftar,sizeof(daftar),1,in)==1)
    {
        if((strcmp(daftar.username,user)==0 && strcmp(daftar.pass,pw)==0)){
            printf("LOGIN BERHASIL\n");
            fclose(in);system("pause");usermenu();
        }
    }rewind(in);
    while(fread(&daftar,sizeof(daftar),1,in)==1){
        if((strcmp(daftar.username,user)!=0 || strcmp(daftar.pass,pw)!=0)){
            printf("LOGIN GAGAL\n");
            fclose(in);system("pause");main();
        }
    }
    fclose(in);
}
		
void usermenu(){
	system("cls");
	puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	printf("\t\t\t\t SELAMAT DATANG \n");
	puts("Menu : ");
	puts("1. Sorting dan Cari Vaksin");
	puts("2. Formulir Pendaftaran");
	puts("3. Exit ");
	printf("Pilihan : "); scanf("%d",&luser);
	 switch(luser){
	case 1:{
		find();
		break;
	}
	case 2:{
		formulir();
		break;
	}
	case 3:{
		main();
		break;
		default :printf ("Error!");
	}
}
}

void find(){
	FILE *sorting;
	char tanggal[100], jenisvaksin[100], lok[100], cari[100];
	int kuotavaksin, i=0, j=0, n=0;
	sorting=fopen("List tanggal.dat","rb");
	while(fread(&a, sizeof(a),1,sorting)==1){
		strcpy(temp[i].tanggal, a.tanggal);
		strcpy(temp[i].jenisvaksin, a.jenisvaksin);
		strcpy(temp[i].lok, a.lok);
		temp[i].kuotavaksin=a.kuotavaksin;
		i++, n++;}
	i=0; j=0;
	for(i=n-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if(temp[j-1].kuotavaksin<temp[j].kuotavaksin){
			temp2=temp[j-1];
			temp[j-1]=temp[j];
			temp[j]=temp2;
			}
		}
	}
	
	for (i=0;i<n;i++){
		printf("%d.\tTanggal\t: %s\n", i+1,temp[i].tanggal);
		printf("\tJenis Vaksin\t: %s\n", temp[i].jenisvaksin);
		printf("\tKuota\t: %d\n", temp[i].kuotavaksin);
		printf("\tTempat\t: %s\n",temp[i].lok);
	}
	fclose(sorting); getchar();
	printf("Jenis vaksin yang dicari : "); gets(cari); system("cls");
	i=0;
	while(i<n && strcmp(temp[i].jenisvaksin,cari)!=0){ 
		i++;
	}
	if(strcmp(cari,temp[i].jenisvaksin)==0){ 
		printf("%d. Tanggal\t: %s\n",i+1,temp[i].tanggal); 
		printf("   Jenis Vaksin\t: %s\n",temp[i].jenisvaksin); 
		printf("   Tempat\t: %s\n", temp[i].lok); 
		printf("   Kuota\t: %d\n",temp[i].kuotavaksin);
		} else{
		printf("Data tidak ditemukan");
	}system("pause"); usermenu();
}

void formulir(){
	char pil[3], tempat[100], jenis[100];
	system ("cls");
	int i=1,n;
	FILE*form; 
	FILE*formu;
	form=fopen("List tanggal.dat","rb+");
	formu=fopen("Formulir.dat","ab");
	puts("\t\t\t================================");
	puts("\t\t\t SELAMAT DATANG DI D'VAKSIN");
	puts("\t\t\t================================");
	printf("\nApakah Pasien Positif Covid atau Tidak? (Ya/No)? : ");scanf("%s",&pil);getchar();
	system ("cls");
    if(strcmp(pil,"NO")==0||strcmp(pil,"No")==0||strcmp(pil,"no")==0){
	while(fread(&a,sizeof(a),1,form)==1){
		printf("%d. Tanggal: %s\n",i,a.tanggal);
		printf("	Tempat: %s\n",a.lok);
		printf("	Jenis Vaksin: %s\n", a.jenisvaksin);
		printf("	Kuota: %d\n", a.kuotavaksin);
		i++;
		}fclose(form);
		printf(" Pilih Tempat: ");gets(datay.tempat);
		printf(" Pilih Jenis Vaksin: ");gets(datay.jenis);
		fwrite(&datay, sizeof(datay),1,formu);
		fclose(formu);
		formu=fopen("Formulir.dat","wb");
		form=fopen("List tanggal.dat","rb+");
		while(fread(&a,sizeof(a),1,form)==1){
			if(strcmp(datay.tempat,a.lok)==0 && strcmp(datay.jenis,a.jenisvaksin)==0){
				if(a.kuotavaksin>0){
					ada=1;
					fseek(form,-sizeof(a),SEEK_CUR);
					a.kuotavaksin-= 1;
					system("cls");
		fwrite(&a,sizeof(a),1,form);
						printf("Nama		 : "); gets(datay.name);
    					printf("NIK			 : "); gets(datay.nik);
    					printf("Alamat		 : "); gets(datay.alamat);
    					printf("Umur		 : "); gets(datay.umur);
    					printf("Jenis Kelamin: "); gets(datay.gender);
    					fwrite(&datay,sizeof(datay),1,formu);
						printf("Pendaftaran Berhasil");fflush(stdin);
						fclose(formu);
	system("cls");
	formu=fopen("Formulir.dat","rb");
	printf("\tBUKTI PENDFATRAN\n");
	while(fread(&datay,sizeof(datay),1,formu)==1){
    printf("Nama		: %s \n",datay.name);
    printf("NIK  		: %s \n",datay.nik);
    printf("Umur  		: %s \n",datay.umur);
    printf("Gender  	: %s \n",datay.gender);
    printf("Alamat 		: %s \n",datay.alamat);
	printf("Lokasi 		: %s \n",datay.tempat);
	printf("Jenis Vaksin: %s \n",datay.jenis);
	}fclose(formu);
				}
				break;
			}
		}
		fclose (form);
		if(ada!=1){
			printf("Data Tidak Ditemukan\n");
		}
		}else{
	printf("Mohon Maaf, Anda Tidak Diperkenankan Melanjutkan Pendaftaran Karena Terjangkit COVID 19\n");
	} system("pause"); usermenu();
}

