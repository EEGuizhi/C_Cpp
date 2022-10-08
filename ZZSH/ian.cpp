#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

const int TOTAL = 2000;
const double A_ = 0.5, B_ = 1.05, STRENGTH_ = 0.9, MUTATION = 0.02, LETHAL = 100;

class cHuman
{
private:
	bool infected, dead;
	int date;
	double a, b, strength;
public:
	cHuman()
	{ 
		infected = dead = false; 
		a = A_; b = B_; strength = STRENGTH_;
	}
	bool IsInfected() { return(infected); }
	bool IsDead() { return(dead); }
	double A() { return(a); }
	double B() { return(b); }
	double S() { return(strength); }
	void SetA(double x) { a = x; }
	void SetB(double x) { b = x; }
	void SetSTRENGTH(double x) { strength = x; }
	void MakeInfected(int day);
	double VirusLevel(int day);
	bool Died(int day);
	bool InfectAnother(cHuman *person2, int day);
};
void cHuman::MakeInfected(int day)
{
	infected = true;
	date = day;
}
double cHuman::VirusLevel(int day)
{	
	if (!infected || day <= date || dead) return(0);
	return(a*pow(b, (double)(day - date)));
}
bool cHuman::Died(int day)
{
	if (dead || !infected) return(false);
	if (VirusLevel(day) >= LETHAL)
	{
		dead = true;
		return(true);
	}
	return(false);
}
bool cHuman::InfectAnother(cHuman *person2, int day)
{
	if (dead || person2->dead) return(false);
	if (infected && person2->infected) return(false);
	if (!infected && !person2->infected) return(false);

	if (infected)
	{
		if (VirusLevel(day)*strength > rand() / (double)RAND_MAX)
		{
			person2->MakeInfected(day);
			person2->SetA(a);
			person2->SetB(b);
			person2->SetSTRENGTH(strength);
			return(true);
		}
	}
	else
	{
		if (person2->VirusLevel(day)*strength > rand() / (double)RAND_MAX)
		{
			MakeInfected(day);
			SetA(person2->a);
			SetB(person2->b);
			SetSTRENGTH(person2->strength);
			return(true);
		}
	}
	return(false);
}

class cCountry
{
private:
	cHuman person[TOTAL];
	int today, healthy, sick, dead;
	double total, total_a, total_b, total_s;
public:
	cCountry()
	{
		today = 0;
		healthy = TOTAL - 1;
		dead = 0;
		total = total_a = total_b = total_s = 0;
		person[0].MakeInfected(0);
	}
	void Tomorrow();
	void RandomInfected(int count);
	void Mutation();
	void Record();
	void Output();
};
void cCountry::Tomorrow()
{
	today++;
	Mutation();
	Record();
	for (int i = 0; i < TOTAL; i++)
	{
		if (person[i].Died(today)) dead++;
	}
}
void cCountry::RandomInfected(int count)
{
	int x, y;
	for (int i = 0; i < count && dead < TOTAL - 1; i++)
	{
		do x = rand() % TOTAL;
		while (person[x].IsDead());
		do y = rand() % TOTAL;
		while (person[y].IsDead() || x == y);		

		if (person[x].InfectAnother(&person[y], today)) healthy--;
	}
}
void cCountry::Mutation()
{
	for (int i = 0; i < TOTAL; i++)
	{
		if (person[i].IsInfected())
		{
			person[i].SetA(person[i].A()*(1 + rand() / (double)RAND_MAX*(MUTATION * 2) - MUTATION));
			person[i].SetB(person[i].B()*(1 + rand() / (double)RAND_MAX*(MUTATION * 2) - MUTATION));
			person[i].SetSTRENGTH(person[i].S()*(1 + rand() / (double)RAND_MAX*(MUTATION * 2) - MUTATION));
		}
	}
}
void cCountry::Record()
{
	for (int i = 0; i < TOTAL; i++)
	{
		if (person[i].IsInfected())
		{
			total_a += person[i].A();
			total_b += person[i].B();
			total_s += person[i].S();
			total += 1;
		}
	}
}
void cCountry::Output()
{	
	sick = TOTAL - healthy - dead;
	cout << "Total=" << TOTAL << endl;
	cout << "Healthy=" << healthy << endl;
	cout << "Died=" << dead << endl;
	cout << "Sick=" << sick << endl;
	cout << "MUTATION=" << MUTATION << endl;
	cout << "Average A=" << total_a / total << " <initial=" << A_ << ">" << endl;
	cout << "Average B=" << total_b / total << " <initial=" << B_ << ">" << endl;
	cout << "Average Strength=" << total_s / total << " <initial=" << STRENGTH_ << ">" << endl << endl;
	//cout << "total_a=" << total_a << " total_b=" << total_b << " total_s=" << total_s << " total=" << total << endl << endl;
}

int main()
{
	srand(10);
	cCountry country;
	for (int i = 0; i < 300; i++)
	{
		country.Tomorrow();
		country.RandomInfected(100);					
	}
	country.Output();
	system("pause");

	return(0);
}
