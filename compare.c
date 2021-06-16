#include<stdio.h>
#include<string.h>
#include<stdbool.h>

FILE *data;
FILE *isi_data;
FILE *form;
void cover();
void adminlogin();
void adminmenu();
void inputjadwal();
void lihatpasien();
void registrasi();
void loginpasien();
void menupasien();
void lihatjadwal();
void find();
void isiform();
int dota,dotb,dotc,i,n,a;
char plogin[50],ulogin[50],c[50],tempvv[50],jenvv[50];
struct{
    char tempat[50],tanggal[50],jenisvaksin[50],user[50],pass[50];
    char userb[50],passb[50],userp[50],passp[50];
    int kuota;
} jadwal,login,loginb,p;

struct{
    char nama[50],jenisk[50],umur[50],alamat[50],noktp[50],tempv[50],jenv[50];
}datap;

void cover(){
   printf("\n\t\t DDDDDDDD   '''   VVV       VVV   AAAAAAAA    KKK   KKK      SSSSSSSSSS    III  NNN     NNN");
 printf("\n\t\t DDDDDDDDD  '''   VVV       VVV  AAA    AAA   KKK  KKK     SSSSSS   SSSSS  III  NNNN    NNN");
 printf("\n\t\t DDD    DDD '''   VVV       VVV  AAA    AAA   KKK KKK       SSSSS     SSS  III  NNNN    NNN");
 printf("\n\t\t DDD    DDD '''   VVV       VVV  AAAAAAVAAA   KKKK            SSSSS        III  NNN N   NNN");
 printf("\n\t\t DDD    DDD        VVV     VVV   AAAAAAVAAA   KKKK               SSSSS     III  NNN  N  NNN");
 printf("\n\t\t DDD    DDD         VVV   VVV    AAA    AAA   KKK KKK      SSS     SSSSS   III  NNN   N NNN");
 printf("\n\t\t DDDDDDDDD           VVV VVV     AAA    AAA   KKK  KKK      SSSS   SSSSSS  III  NNN    NNNN");
 printf("\n\t\t DDDDDDDD              VVVV      AAA    AAA   KKK    KKK     SSSSSSSSSS    III  NNN     NNN");
 printf("\n\t\t=============================================================================================\n");

 printf("\n\n");
}

void main(){
    system("cls");cover();
    puts("1. Login Admin");
    puts("2. Login Pasien");
    puts("3. Registrasi Pasien");
    puts("4. Exit");
    printf("\n\nPilih Menu : ");
    scanf("%d",&dota);
    switch(dota)
    {
    case 1:
        adminlogin();
        break;
    case 2:
        loginpasien();
        break;
    case 3:
        registrasi();
        break;
    case 4:
        printf("\nTerima kasih, Selamat Datang Kembali\n");
        break;
    }
}
void adminlogin(){
    system("cls");cover();
    puts("\t\t\t\t Login Admin\n");
    printf("username : ");
    fflush(stdin);
    gets(login.user);
    printf("password : ");
    fflush(stdin);
    gets(login.pass);
    if(strcmp(login.user,"admin")==0&&strcmp(login.pass,"admin")==0)
    {
        puts("---Login Berhasil---");
        system("pause");
        adminmenu();
    }
    else
    {
        puts("--Username atau Password salah--");
        system("pause");
        main();
    }

}
void adminmenu(){
    system("cls");cover();
    puts("==Hello Admin==");
    puts("1. Input Jadwal Vaksin");
    puts("2. Lihat Pasien Vaksin");
    puts("3. Kembali");
    printf("\nPilihan : ");
    scanf("%d",&dotb);
    switch(dotb)
    {
    case 1:{
        inputjadwal();
        break;
    }
    case 2:{
        lihatpasien();
        break;
    }
    case 3:{
        main();
        break;
    }
    default :
        printf("ERROR!!");
    }
}
void inputjadwal(){
    system("cls");cover();
    FILE *data;
    puts("\t\t\t<===List Jadwal Vaksinasi===>");
    puts("Tanggal\t\t\tTempat\t\tKuota\t\tJenis Vaksin");
    data=fopen("jadwalvaksin.dat","rb");
    while(fread(&jadwal,sizeof(jadwal),1,data)==1){
    printf("\n%s", jadwal.tanggal);
    printf("\t\t%s", jadwal.tempat);
    printf("\t\t%d", jadwal.kuota);
    printf("\t\t%s", jadwal.jenisvaksin);
    }
    fclose(data);
    data=fopen("jadwalvaksin.dat","ab");
    printf("\nInput Tanggal : ");fflush(stdin);
    gets(jadwal.tanggal);
    printf("Input Tempat  : ");
    gets(jadwal.tempat);
    printf("Kuota Vaksin : ");fflush(stdin);
    scanf("%d", &jadwal.kuota);
    printf("Jenis Vaksin : ");fflush(stdin);
    gets(jadwal.jenisvaksin);
    fwrite(&jadwal, sizeof(jadwal),1, data);
    fclose(data);
    adminmenu();

}
void lihatpasien(){
    system("cls");cover();
    form=fopen("formulir.dat","rb");
    while(fread(&datap,sizeof(datap),1,form)==1){
            puts("============================");
            printf("\nNama          : %s",datap.nama);
            printf("\nJenis Kelamin : %s",datap.jenisk);
            printf("\nUmur          : %s",datap.umur);
            printf("\nNo.KTP        : %s",datap.noktp);
            printf("\nAlamat        : %s",datap.alamat);
            printf("\nTempat Vaksin : %s",datap.tempv);
            printf("\nJenis Vaksin  : %s\n",datap.jenv);
            puts("============================");
    }
    fclose(form);
    system("pause");
    adminmenu();
}
void registrasi(){
    system("cls");cover();
    puts("---Silahkan Registrasi---");
 isi_data=fopen("Akun pasien.dat","ab");

 {
  printf("username\t: ");fflush(stdin);
        gets(loginb.userb);
  printf("password\t: ");fflush(stdin);
        gets(loginb.passb);
  fwrite(&loginb, sizeof(loginb),1, isi_data);
 }
 fclose(isi_data);
 main();
}
void loginpasien(){
    system("cls");cover();
    puts("---Silahkan Masuk---");
	printf("Username : ");fflush(stdin); gets(ulogin);
    printf("\nPassword : "); gets(plogin);
    isi_data=fopen("Akun pasien.dat","rb");
    while(fread(&loginb,sizeof(loginb),1,isi_data)==1)
    {
        if((strcmp(loginb.userb,ulogin)==0 && strcmp(loginb.passb,plogin)==0)){
            printf("----Login berhasil----\n");
            fclose(isi_data);system("pause");menupasien();
        }
    }rewind(isi_data);
    while(fread(&loginb,sizeof(loginb),1,isi_data)==1){
        if((strcmp(loginb.userb,ulogin)!=0 || strcmp(loginb.passb,plogin)!=0)){
            printf("----Login GAGAL----\n");
            fclose(isi_data);system("pause");main();
        }
    }
    fclose(isi_data);
    main();
}
void menupasien(){
    system("cls");cover();
    puts("==Hello Mr or Mrs==");
    puts("1. Lihat Jadwal Jenis Vaksin");
    puts("2. Isi Formulir Pendaftaran");
    puts("3. Kembali");
    printf("\nPilihan : ");
    scanf("%d",&dotc);
    fflush(stdin);
    switch(dotc)
    {
    case 1:{
        lihatjadwal();
        break;
    }
    case 2:{
        isiform();
        break;
    }
    case 3:{
        main();
        break;
    }
    }

}
void lihatjadwal(){
    system("cls");cover();
    puts("\t\t\t<===List Jadwal Vaksinasi===>");
    puts("Tanggal\t\t\tTempat\t\tKuota\t\tJenis Vaksin");
    data=fopen("jadwalvaksin.dat","rb");
    while(fread(&jadwal,sizeof(jadwal),1,data)==1){
        printf("%s", jadwal.tanggal);
        printf("\t\t%s", jadwal.tempat);
        printf("\t\t%d", jadwal.kuota);
        printf("\t\t%s\n", jadwal.jenisvaksin);
    }
    fclose(data);
    system("pause");
    menupasien();
}


void isiform(){
    system("cls");cover();
    FILE *form;
    printf("Apakah anda terinveksi Virus Covid-19?(Y/N) : ");
    gets(c);
    if (strcmp(c,"N")==0 || strcmp(c,"n")==0) {

    	puts("\n\t\t\t<===List Jadwal Vaksinasi===>");
    	puts("Tanggal\t\t\tTempat\t\tKuota\t\tJenis Vaksin");
    	data=fopen("jadwalvaksin.dat","rb");
    	while(fread(&jadwal,sizeof(jadwal),1,data)==1){
        printf("%s", jadwal.tanggal);
        printf("\t\t%s", jadwal.tempat);
        printf("\t\t%d", jadwal.kuota);
        printf("\t\t%s\n", jadwal.jenisvaksin);
    	}
    	fclose(data);

    	printf("\nPilih tempat Vaksin\t: "); gets(tempvv);
    	printf("Pilih jenis Vaksin\t: "); gets(jenvv);

    	 data=fopen("jadwalvaksin.dat","rb");
        while(fread(&jadwal,sizeof(jadwal),1,data)==1)
        {
            if((strcmp(jadwal.tempat,tempvv)==0 && strcmp(jadwal.jenisvaksin,jenvv)==0))
            {
                if(jadwal.kuota>0){
                    data=fopen("jadwalvaksin.dat","ab+");
                    while(fread(&jadwal,sizeof(jadwal),1,data)==1){
                        jadwal.kuota--;
                    } fwrite(&jadwal,sizeof(jadwal),1,data);
					fclose(data);
                }
                form=fopen("formulir.dat","ab");
     		    printf("\nNama          : ");fflush(stdin); gets(datap.nama);
     		    printf("Jenis Kelamin : ");gets(datap.jenisk);
     		    printf("Umur          : ");gets(datap.umur);
     		    printf("No. KTP       : ");gets(datap.noktp);
     	 	    printf("Alamat        : ");gets(datap.alamat);
        		strcpy(datap.tempv,tempvv); strcpy(datap.jenv,jenvv);
        		fwrite(&datap, sizeof(datap),1, form);
       			fclose(form);
                printf("--Selamat Pendaftaran Vaksinasi Berhasil--\n");
                printf("\n--Tekan Enter untuk Cetak Bukti Pendaftaran--\n");
                system("pause"); system("cls"); cover();
                form=fopen("formulir.dat","rb");
   				while(fread(&datap,sizeof(datap),1,form)==1){
        	    	puts("============================");
            		printf("\nNama          : %s",datap.nama);
            		printf("\nJenis Kelamin : %s",datap.jenisk);
            		printf("\nUmur          : %s",datap.umur);
            		printf("\nNo.KTP        : %s",datap.noktp);
            		printf("\nAlamat        : %s",datap.alamat);
            		printf("\nTempat Vaksin : %s",datap.tempv);
            		printf("\nJenis Vaksin  : %s\n",datap.jenv);
            		puts("============================");
    			} fclose(form);
                puts("--Bukti Pendaftaran Sudah Tercetak--");
                system("pause");
                menupasien();
            }
        }
        rewind(data);
        while(fread(&jadwal,sizeof(jadwal),1,data)==1)
        {
            if((strcmp(jadwal.tempat,tempvv)!=0 || strcmp(jadwal.jenisvaksin,jenvv)!=0))
            {
                printf("--Maaf Pendaftaran GAGAL--");
                fclose(data);
                system("pause");
                menupasien();
            }
        }
    }
    else if (strcmp(c,"Y")==0|| strcmp(c,"y")==0){
        puts("---Maaf anda tidak bisa mendaftar vaksinasi---");
        system("pause");
        menupasien();
    }
    else {
        puts("ERROR NGAB!!!");
        system("pause");
    }
}
