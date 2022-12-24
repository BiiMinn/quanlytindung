#include<stdio.h>
#include<stdlib.h>
// note: int a = 0;  thi doi voi con tro int*p_A = NULL;
int m=50;// so o nho cung cap cho con tro p_s
int n;
int i;

/*typedef struct customer
	{
		char name[30];
		char address[50];
		int id;
		int pass;
		float money;
	} cus_t;
	*/
typedef struct kh
{
	char ten[49];
	char dia_chi[50];
	int id;
	int mat_khau;
	float so_tien;
	// init variable
}kh_t;


int main()
{
	fflush(stdin);
	printf("/n Nhap so hoc sinh:");
	scanf("%d",&n);
//	kh_t kh_1;
	kh_t *p_s;
//	p_s = &kh_1;
//	p_s = (struct kh *) malloc(N*sizeof(struct kh));
	p_s = (kh_t *) malloc(m*sizeof(kh_t));
	
	// enter variable
