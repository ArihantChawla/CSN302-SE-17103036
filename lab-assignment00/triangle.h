// I'm going to intentionally mock you in this assignment because I know this has been mostly allocated to teach git, teaching which using CLI was not a good idea tbh. - Arihant


#define epsilon 0.0000001f

//Triangle Independent Functions
void swap(double* a, double* b);
//Triangle Specific Functions. 
int isTriangle(double A, double B, double C);
void orderSides(double* A, double* B, double* C);
int isRightAngled(double A, double B, double C);
int checkType(double A, double B, double C);



/** FUCNTIONS BEGIN **/
// Triangle Independent Functions

double fabs(double a) {   // Should have just used math library. :)
	if (a >= 0) return a;
	return -1*a; 
}

int isEqual(double a, double b) {
   if(fabs(a - b) < epsilon)
      return 1; //they are same
      return 0; //they are not same
}

void swap(double* a, double* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Triangle Specific Functions
int isTriangle(double A, double B, double C) {
	if (A + B < C) return 0;
	if (B + C < A) return 0;
	if (C + A < B) return 0;
	return 1;
}


int isRightAngled(double A, double B, double C) { 
// Working with double (datatype) equality in C is a headache. Especially in squared powers. So I've used doubles for this. Should have just coded in python :(
	if ( isEqual(A*A , B*B + C*C) || isEqual(B*B , C*C + A*A) || isEqual(C*C , A*A + B*B))  { return 1; }
	return 0;
}


/* 
 * Function returns int for: (I will limit myself to these classes as the ambiguity in this question 
	[which I assume is intentional to make people ask questions] 
	 	allows me to be this restrictive and get away with it.
	)
 * -1 : Not a Triangle
 *  0 : Scalene
 *  1 : Right Angled // 1 because right angled triangles occur a lot in artificial structures	
 *  2 : Isosceles
 *  3 : Equilateral
 *
 */

int checkType(double A, double B, double C) {

	if (!isTriangle(A,B,C)) return -1;
	//printf("%lf %lf %lf\n", A,B,C);
	if (A == B && B == C) return 3;
	if (A == B || B == C) return 2;
	if (isRightAngled(A,B,C)) return 1; // Costlier
	return 0;
}

