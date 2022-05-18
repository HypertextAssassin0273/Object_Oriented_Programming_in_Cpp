#include<iostream>
#include<time.h>
using namespace std;

class Matrix{
protected:
	void* data;
	
	Matrix(int height, int width, void* data)noexcept://ctor
		height(height),width(width),data(data){}
	
public:
	const int height, width;
	
    virtual double getElem(int, int)const = 0;
    virtual void setElem(int, int, double) = 0;
	
	virtual Matrix* add(Matrix*)const = 0;
	virtual Matrix* multiply(Matrix*)const = 0;
	
	virtual string toString()const = 0;//extra, declared for polymorphism testing
	virtual void display()const = 0;//extra, for debugging & testing
	
	virtual ~Matrix(){}//virtual dtor
	
protected:
	static inline double min(double a, double b) {
    	return a < b ? a : b;
    }
/*NOTES:
	1) we can't use object type of Matrix (since it's not allowed in abstract class) in the given scenario
	   but we can use pointer/reference type (although it will perform "Object-Slicing")
	
	2) The above atrributes are moved up from derived/concrete classes to this/interface class
	   so that "Object-Slicing" does not affect our operations when using Matrix ptr to access 
	   concrete class' virtual methods.
	
	3) In order to avoid code duplicacy, static min method is also moved up to this/interface class 
	   since it's present in all concrete classes without any changes.
*/
};

class Matrix2DArray final: public Matrix {
public:	
    Matrix2DArray(int height, int width)noexcept://ctor
		Matrix(height, width, new double*[height]){//NOTE: void pointer will now point to dynamic 2D array
			for (int i=0;i<height;++i)
				((double**)data)[i]=new double[width];
		}
	
    double getElem(int i, int j)const override{
        return ((double**)data)[i][j];
    }
	
    void setElem(int i, int j, double value) override{ 
		((double**)data)[i][j] = value;
	}
	
	Matrix2DArray* add(Matrix* other)const override{
		if(height!=width){
			cout<<"0 (not possible)";
			return new Matrix2DArray(0, 0);//empty matrix
		}
        Matrix2DArray* temp_ptr = new Matrix2DArray(height, width);
		for (int i = 0, j; i < height; ++i)
            for (j = 0; j < width; ++j)
                ((double**)temp_ptr->data)[i][j] = ((double**)data)[i][j] + other->getElem(i,j);
        return temp_ptr;
	}//NOTE: "type-casting" is req. for objects/variables pointed by void* pointers
	
    Matrix2DArray* multiply(Matrix* other)const override{
    	if(width != other->height){
			cout<<"0 (not possible)";
			return new Matrix2DArray(0, 0);//empty matrix
		}
        Matrix2DArray* temp_ptr = new Matrix2DArray(height, other->width);
		for (int i = 0, j, k; i < height; ++i)
            for (j = 0; j < other->width; ++j) {
                double total = 0;
                for (k = 0; k < width; ++k)
                    total += ((double**)data)[i][k] * other->getElem(k,j);
                ((double**)temp_ptr->data)[i][j] = total;
            }
        return temp_ptr;
    }
	
	string toString()const override{
		string temp_str;
		for(int i=0,j;i<height;++i)
			for(j=0;j<width;++j)
				temp_str += to_string(((double**)data)[i][j]) + ' ';
		return temp_str;
	}
	
    double min()const {//extra
        double value = ((double**)data)[0][0];
        for (int i = 0, j; i < height; ++i)
            for (j = 0; j < width; ++j)
                value = Matrix::min(value, ((double**)data)[i][j]);
        return value;
    }
    
    void display()const override{//extra
		for(int i=0,j;i<height;++i){
			for(j=0;j<width;++j)
				cout<<((double**)data)[i][j]<<' ';
			cout<<'\n';
		}
	}
	
	~Matrix2DArray(){//dtor
		for(int i = 0; i < height; ++i)
        	delete[] ((double**)data)[i];   
		delete[] (double**)data;
	}
};

class MatrixLin : public Matrix{
protected:
	MatrixLin(int height, int width)noexcept://ctor
		Matrix(height, width, new double[height*width]){}//NOTE: void pointer will now point to linear dynamic 1D array
	
public:
	virtual Matrix2DArray* delinearize()const = 0;
	
	double getElem(int i, int j)const override{
        return ((double*)data)[i*width+j];
    }
	
    void setElem(int i, int j, double value) override{ 
		((double*)data)[i*width+j] = value;
	}
	
	string toString()const override{
		string temp_str;
		for(int i=0;i<height*width;++i)
			temp_str += to_string(((double*)data)[i]) + ' ';
		return temp_str;
	}
	
	void display()const override{//extra
		for(int i=0;i<height*width;++i)
				cout<<((double*)data)[i]<<' ';
			cout<<'\n';
	}
	
	virtual ~MatrixLin(){//dtor
		delete[] (double*)data;
	}
};

class MatrixRowWise : public MatrixLin {
public:
    MatrixRowWise(int height, int width)noexcept://ctor
    	MatrixLin(height, width){}

    MatrixRowWise* add(Matrix* other)const override{
		if(height != other->height || width != other->width){
			cout<<"0 (not possible)";
			return new MatrixRowWise(0, 0);//empty matrix
		}
        MatrixRowWise* temp_ptr = new MatrixRowWise(height, width);
        for (int i = 0, j; i < height; ++i)
            for (j = 0; j < width; ++j)
        		temp_ptr->setElem(i, j, ((double*)data)[i*width+j] + other->getElem(i, j));
        return temp_ptr;
    }
	
	MatrixRowWise* multiply(Matrix* other)const override{//row-wise multiplication???, incomplete
        MatrixRowWise* temp_ptr = new MatrixRowWise(height, width);
//        for (int i = 0; i < this.width; i++) {
//            double value = this.data[i] * obj.getElem(i, 0);
//            M.setElem(i, 0, value);
//        }
        return temp_ptr;
    }
	
	Matrix2DArray* delinearize()const override{
        Matrix2DArray* temp_ptr = new Matrix2DArray(height, width);
        for(int i=0,j;i<height;++i)
			for(j=0;j<width;++j)
				temp_ptr->setElem(i, j, ((double*)data)[i*width+j]);
        return temp_ptr;
    }
};

class MatrixColWise : public MatrixLin {
public:
    MatrixColWise(int height, int width)noexcept://ctor
    	MatrixLin(height, width){}

    MatrixColWise* add(Matrix* other)const override{
		if(height != other->height || width != other->width){
			cout<<"0 (not possible)";
			return new MatrixColWise(0, 0);//empty matrix
		}
        MatrixColWise* temp_ptr = new MatrixColWise(height, width);
        for (int i = 0, j; i < height; ++i)
            for (j = 0; j < width; ++j)
        		temp_ptr->setElem(i, j, ((double*)data)[i*width+j] + other->getElem(i, j));
        return temp_ptr;
    }
	
	MatrixColWise* multiply(Matrix* other)const override{//col-wise multiplication???, incomplete
        MatrixColWise* temp_ptr = new MatrixColWise(height, width);
//        for (int i = 0; i < this.width; i++) {
//            double value = this.data[i] * obj.getElem(i, 0);
//            M.setElem(i, 0, value);
//        }
        return temp_ptr;
    }
	
	Matrix2DArray* delinearize()const override{
        Matrix2DArray* temp_ptr = new Matrix2DArray(width, height);
        for(int i=0,j;i<height;++i)
			for(j=0;j<width;++j)
				temp_ptr->setElem(j, i, ((double*)data)[i*width+j]);
        return temp_ptr;
    }
};


void test_case_1(){
	Matrix2DArray mat1(2,2), mat2(2,2);
	
	mat1.setElem(0,0,2.2);
	mat1.setElem(0,1,1.1);
	mat1.setElem(1,0,4.4);
	mat1.setElem(1,1,3.3);
	
	cout<<"Matrix 1:\n";
	mat1.display();
	cout<<"Min. Value:\n"
		<<mat1.min()<<'\n';
	
	mat2.setElem(0,0,12.12);
	mat2.setElem(0,1,11.11);
	mat2.setElem(1,0,4.4);
	mat2.setElem(1,1,23.23);
	
	cout<<"\nMatrix 2:\n";
	mat2.display();
	cout<<"Min. Value:\n"
		<<mat2.min()<<'\n';
	
	cout<<"\nResultant Matrix after Addition:\n";
	Matrix2DArray* mat3_ptr= mat1.add(&mat2);
	mat3_ptr->display();
	delete mat3_ptr;
	
	cout<<"\nResultant Matrix after Multiplication:\n";
	mat3_ptr= mat1.multiply(&mat2);
	mat3_ptr->display();
	
	cout<<"\nConverted Matrix to String:\n"
		<<mat3_ptr->toString();
	delete mat3_ptr;
/* NOTE: 
	we can avoid explicit deletion by using smart pointers
*/
}

void test_case_2(){
	int r1=4, c1 =2, /* h1 w1 */
		r2=2, c2= 3; /* h2 w2 */
	Matrix2DArray mat1(r1,c1),
				  mat2(r2,c2);
	
	for(int i=0,j;i<r1;++i)
		for(j=0;j<c1;++j)
			mat1.setElem(i,j,rand()%20+1);		
	cout<<"Matrix 1:\n";
	mat1.display();
	
	for(int i=0,j;i<r2;++i)
		for(j=0;j<c2;++j)
			mat2.setElem(i,j,rand()%20+1);
	cout<<"\nMatrix 2:\n";
	mat2.display();
	
	cout<<"\nResultant Matrix after Addition:\n";
	Matrix2DArray* mat3_ptr= mat1.add(&mat2);
	mat3_ptr->display();
	delete mat3_ptr;
	
	cout<<"\nResultant Matrix after Multiplication:\n";
	mat3_ptr= mat1.multiply(&mat2);
	mat3_ptr->display();
	delete mat3_ptr;
}

void test_case_3(){
	int r1=1, c1 =3,
		r2=3, c2= 2;
	Matrix* matrices[]={new Matrix2DArray(r1,c1), 
					    new Matrix2DArray(r2,c2)};
	//i.e array of pointers holding addresses of dynamic Matrix objects
	
	for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
			matrices[0]->setElem(i,j,rand()%10+1);
	cout<<"Matrix 1:\n";
	matrices[0]->display();
	
	for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
			matrices[1]->setElem(i,j,rand()%10+1);
	cout<<"Matrix 2:\n";
	matrices[1]->display();
	
	cout<<"\nResultant Matrix after Addition:\n";
	Matrix* mat3_ptr= matrices[0]->add(matrices[1]);
	mat3_ptr->display();
	delete mat3_ptr;

	cout<<"\nResultant Matrix after Multiplication:\n";	
	mat3_ptr= matrices[0]->multiply(matrices[1]);
	mat3_ptr->display();
	delete mat3_ptr;
	
	for (int i = 0; i < 2; ++i)
		delete matrices[i];
	//Note: it's a good programming practice to clear dynamic resources explicitly/manually
}

void test_case_4(){
	//MatrixRowWise <= MatrixLin

	int r1=2, c1 =3, /* h1 w1 */
		r2=3, c2= 3; /* h2 w2 */
	MatrixRowWise mat1(r1,c1),
				  mat2(r2,c2);
	
	for(int i=0,j;i<r1;++i)
		for(j=0;j<c1;++j)
			mat1.setElem(i,j,i*c1+j+1);		
	cout<<"Linear Matrix 1:-\n";
	mat1.display();
	cout<<"Delinearized M#1:\n";
	Matrix2DArray* temp_mat_ptr = mat1.delinearize();
	temp_mat_ptr->display();
	delete temp_mat_ptr;
	
	for(int i=0,j;i<r2;++i)
		for(j=0;j<c2;++j)
			mat2.setElem(i,j,i*c2+j+1);
	cout<<"\nLinear Matrix 2:-\n";
	mat2.display();
	cout<<"Delinearized M#2:\n";
	temp_mat_ptr = mat2.delinearize();
	temp_mat_ptr->display();
	delete temp_mat_ptr;
	
	cout<<"\nResultant Matrix after Addition:\n";
	MatrixRowWise* mat3_ptr= mat1.add(&mat2);
	mat3_ptr->display();
	delete mat3_ptr;
	
//	cout<<"\nResultant Matrix after Multiplication:\n";//not complete
//	mat3_ptr= mat1.multiply(&mat2);
//	mat3_ptr->display();
//	delete mat3_ptr;
}

void test_case_5(){
	//MatrixColWise <= MatrixLin

	int r1=2, c1 =3, /* h1 w1 */
		r2=3, c2= 3; /* h2 w2 */
	MatrixColWise mat1(r1,c1),
				  mat2(r2,c2);
	
	for(int i=0,j;i<r1;++i)
		for(j=0;j<c1;++j)
			mat1.setElem(i,j,i*c1+j+1);		
	cout<<"Linear Matrix 1:-\n";
	mat1.display();
	cout<<"Delinearized M#1:\n";
	Matrix2DArray* temp_mat_ptr = mat1.delinearize();
	temp_mat_ptr->display();
	delete temp_mat_ptr;
	
	for(int i=0,j;i<r2;++i)
		for(j=0;j<c2;++j)
			mat2.setElem(i,j,i*c2+j+1);
	cout<<"\nLinear Matrix 2:-\n";
	mat2.display();
	cout<<"Delinearized M#2:\n";
	temp_mat_ptr = mat2.delinearize();
	temp_mat_ptr->display();
	delete temp_mat_ptr;
	
	cout<<"\nResultant Matrix after Addition:\n";
	MatrixColWise* mat3_ptr= mat1.add(&mat2);
	mat3_ptr->display();
	delete mat3_ptr;
	
//	cout<<"\nResultant Matrix after Multiplication:\n";//not complete
//	mat3_ptr= mat1.multiply(&mat2);
//	mat3_ptr->display();
//	delete mat3_ptr;
}


int main(){
	srand(time(NULL));
	//NOTE: generates different time-seed to produce different set of no.s for rand()

	test_case_1();  //Matrix2DArray, same dimension operations
//	test_case_2();  //Matrix2DArray, different dimension operations
//	test_case_3();  //Matrix2DArray, polymorphism testing (using Base/Abstract class ptr to point Concrete Classes)
//	test_case_4();  //MatrixRowWise, delinearized Row wise matrix operations
//	test_case_5();  //MatrixColWise, delinearized Colomn wise matrix operations
    return 0;
}
