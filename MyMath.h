#ifndef MYMATH_H_INCLUDED
#define MYMATH_H_INCLUDED
#include<iostream>
using namespace std;
// i will add more and more mathematical functions but i just need to fix a couple of accuracy related problems
int GetNumWithoutDecimalPoints(double n);
int Ceil(double number);
double Floor(double number);

GetNumWithoutDecimalPoints(double n) // i dont remember what this one was for, and it seems useless
{
    return (n -= Floor(n));
}

double W(double value)	// a horrible attempt to calculate lambert w function
{
    double lambert = 0;
    double w = -100;
    double euler = 2.718282;
    while (true)
    {
        lambert = w * pow(euler, w);

        if ((value - lambert) <= 0.00001)
            break;

        w += 0.00001;
    }
    return w;
}

int Ceil(double number)
{
    int x = number;
    double num = number - int(number);

    if (num != 0)
        x += 1;
    return x;
}
double NormalAngle(double angle)
{
    double FA = angle;
    int num = 0;

    if (angle > 360)
    {
         num = Ceil(angle /360 );
         FA = FA - 360 * (num - 1);

    }



    return FA;
}
double DTR (double angle)	// degrees to radian
{
	double Pi = 3.141593;
	double RD = angle*(Pi/180);
	
	return RD;
}
double RTD (double REX)	// radian to degrees
{
	double Pi = 3.141593;
	double angle = REX*(180/Pi);
	
	return angle;
}

int RefAngle(double angle)
{
    int refAng = 0;
    angle = NormalAngle(angle);

    if (angle > 0 && angle <= 90)
    {
        refAng = angle;
    }

    else if (angle > 90 && angle <= 180)
    {
        refAng = 180 - angle;
    }
    else if (angle > 180 && angle <= 270)
    {
        refAng = angle - 180;
    }
    else if (angle > 270 && angle <= 360)
    {
        refAng = 360 - angle;
    }
    return refAng;
}
int Quadrant(double angle)
{
    int quadrant = Ceil(NormalAngle(angle) / 90);

    return quadrant;

}
double Floor(double number)
{
    int x = number;
    x = int(x);
    return x;
}

double Round(double number)
{
    int x = number;
    double num = number - int(number);

    if (num >= 0.5)
        x += 1;
    else
        x = x;

    return x;
}

long int factorial(int num)
{
    long int result = 1;
    if (num == 0 || num == 1)
        return 1;
    else
        for (int i = 1; i <= num; i++)
        {
            result *= i;
        }
    return result;
}
double pow(double b, double p)
{
    double power = 1;
    if (p == 0)
        return 1;
    else if (p == 1)
    {
        return b;
    }
    else if (p == -1)
        return 1 / b;

    else if (p>1)
    {

        for (int i = 0; i < p; i++)
        {
            power *= b;
        }
    }
    else 
    {
        p = p * -1;
        for (int i = 0; i < p; i++)
        {
            power *= b;
        }
        power = (1 / power);
    }

    return power;
}

double DegToRadian(double angle) 		// specific
{
    angle = RefAngle(angle);
    double Pi = 3.141593;
    double Radian = angle * (Pi / 180.0);
    return Radian;
}

double Sin(double AngD)
{
    int quadrant = Quadrant(AngD);

    if (AngD == 0 || AngD == 180 || AngD == 360)
        return 0;

    double convert = DegToRadian(AngD);
    double result = 0;
    int SC = 1;
    for (int i = 1; i <= 15; i += 2)
    {
        double OP = pow(convert, i) / double(factorial(i));
        if (SC % 2 == 0)
            result -= OP;

        else
            result += OP;

        SC++;

    }
    if (quadrant != 1 && quadrant != 2)
        result *= -1;
    return result;
}

double root(double value, int rt)    // calculating roots using Newton's Method. 
{

    double xOFn = 100;

    for (int i = 0; i < 20; i++)
    {
        double fOFx = pow(xOFn, rt) - value;
        double fDx = rt * pow(xOFn, rt - 1);
        xOFn = xOFn - (fOFx / fDx);

    }


    return xOFn;

}
double Cos(double angle)
{
    int quad = Quadrant(angle);

    if (angle == 90 || angle == 270)
    {
        return 0;
    }

    double initial = 1 - pow(Sin(angle), 2);
    double cosX = root(initial, 2);
    if (quad == 2 || quad == 3)
    {
        cosX *= -1;
    }
    return cosX;
}


double Tan(double angle)
{
    double result = (Sin(angle) / Cos(angle));
    if (angle == 45 || angle == 225)
        return 1;
    else if (angle == 135 || angle == 315)
    {
        return -1;
    }

    return result;
}

long double Csc(double angle)
{
    long double cscx = 1.0 / (Sin(angle));

    return cscx;
}
long double Sec(long double angle)
{
    long double secx = 1.0 / (Cos(angle));

    return secx;
}
double Cot(double angle)
{
    double cotx = Cos(angle)/Sin(angle);

    return cotx;
}



class Angle		// a totally useless class, but i just made it to confirm that everything works properly
{
	private:
		double angle;
		
	public:
		
		double getAngle()
		{
			return angle;
		}
		void setAngle(double a)
		{
			angle = a;
		}
	void PrintAllTrigs()
{
	
	cout << "Sin " << angle << " =  "<< Sin(angle) << endl;
	cout << "Cos " << angle << " =  "<< Cos(angle) << endl;
	cout << "Tan " << angle << " =  "<< Tan(angle) << endl;
	cout << "Sec " << angle << " =  "<< Sec(angle) << endl;
	cout << "Csc " << angle << " =  "<< Csc(angle) << endl;
	cout << "Cot " << angle << " =  "<< Cot(angle) << endl;
}
};

#endif // MYMATH_H_INCLUDED

