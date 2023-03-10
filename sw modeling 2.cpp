// sw modeling 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <list>
#include <memory>
static double total_income;
class owner
{
private :
	string phNum;
	string mail;
public :
	void setPhoneNumber(string p)
	{
		phNum = p;
	}
	string getPhoneNUmber()
	{
		return phNum;
	}
	void setMail(string m)
	{
		mail = m;
	}
	string getMail()
	{
		return mail;
	}
};
class vehicle
{
private :
	string modelNmae;
	string id;
	owner vehicleOwner;
	int modelYear;
	int width; 
	int length; 
public :
	vehicle()
	{
		modelNmae = " ";
		id = " ";
		modelYear = 0;
		width = 0; 
		length = 0; 
	}
	void setModelName(string n )
	{
		modelNmae = n; 
	}
	string getModelName()
	{
		return modelNmae; 
	}
	void setId(string i)
	{
		id = i;
	}
	string getId()
	{
		return id;
	}
	void setModelYear(int y)
	{
		modelYear = y; 
	}
	int getModelYear()
	{
		return modelYear; 
	}
	void setLength(int l)
	{
		length = l; 
	}
	int getLength()
	{
		return length; 
	}
	void setWidth(int w)
	{
		width = w; 
	}
	int getWidth()
	{
		return width; 
	}
	void setOwner(owner obj)
	{
		vehicleOwner = obj;
	}
	owner getOwner()
	{
		return vehicleOwner;
	}
	

};
class timee
{
private:
	int timeInH;
	int timeInM;
	int tiemOutH;
	int tiemOutM;
public:
	timee()
	{
		timeInH = 0;
		timeInM = 0;

	}
	void setTimeInH(int h)
	{
		timeInH = h;
	}
	int getTimeInH()
	{
		return timeInH;
	}
	void setTimeInm(int m)
	{
		timeInM = m;
	}
	int getTimeInm()
	{
		return timeInM;
	}
	void setTimeOutH(int h)
	{
		tiemOutH = h;
	}
	int getTimeOutH()
	{
		return tiemOutH;
	}
	void setTimeOutM(int m)
	{
		tiemOutM = m;
	}
	int getTimeOutM()
	{
		return tiemOutM;
	}
};
class slot
{
private :
	int full; 
	vehicle car;
	timee t;
	int length;
	int width;
 public :
	 slot()
	 {
		 full = 0;
	 }
	 void setLength(int l)
	 {
		 length = l;
	 }
	 int getLength()
	 {
		 return length;
	 }
	 void setWidth(int w)
	 {
		 width = w;
	 }
	 int getWidth()
	 {
		 return width;
	 }
	 void setFull(int f)
	 {
		
		 full = f;
	 }
	 int getFull()
	 {
		 return full;
	 }
	 void setCar(vehicle& obj)
	 {
		 car = obj;
	 }
	 vehicle getCar()
	 {
		 return car;
	 }
	 void setTime(timee tmp )
	 {
		 t = tmp;
	 }
	 timee getTime()
	 {
		 return t;
	 }
};
class parking
{
private :
	slot cars[10];
public :
	parking()
	{
		
	}
	void setSlot( int index, slot& obj )
	{
		cars[index] = obj; 
	
	}
	slot getSlot( int index)
	{
		return cars[index];
	}


};
class parkingbuilder
{
protected :
	parking g;
public :
	void setParking(parking& garage)
	{
		g = garage;
	}
	virtual void buildSmallSlots() = 0;
	virtual void buildBigSlots() = 0;
	parking getParking()
	{
		return g;
	}
};
class concereteParkingBuilder : public parkingbuilder
{
public :

	void buildSmallSlots()
	{
		for (size_t i = 0; i < 5; i++)
		{
			slot s;
			s.setLength(200);
			s.setWidth(120);
			g.setSlot(i, s);
		}
	}
	void buildBigSlots()
	{
		for (size_t i = 5; i < 10; i++)
		{
			slot s;
			s.setLength(180);
			s.setWidth(100);
			g.setSlot(i, s);
		}
	}
	
};
class parkingdirector
{
private :
	parkingbuilder *builder;
public :
	parkingdirector(){}
	parkingdirector(parkingbuilder* obj)
	{
		builder = obj;
	}
	parking construct()
	{
		builder->buildSmallSlots();
		builder->buildBigSlots();
		return builder->getParking();
	}
};

class checksize
{
public :
	checksize(){}
	bool checkmax(parking & garage)
	{
		for (size_t i = 0; i < 10; i++)
		{
			slot s = garage.getSlot(i);
			if (s.getFull() == 0)
			{
				return false;
			}
		}
		return true;
	}
};

class display
{
protected:
	
	slot s;
public :
	display(){}
	
	virtual void print(parking & garage) = 0;

    

};
class displaybigslots : public display
{
public :
	void print(parking &garage)
	{
		for (size_t i = 0; i < 5; i++)
		{

			
			s = garage.getSlot(i);
			int x = s.getFull();
			if (x == 1)
			{
				cout << i + 1 << "->" << "$" << endl;
			}
			else
			{
				cout << i + 1 << "->" << "_" << endl;
			}
		}
	}
};
class displaysmallslots : public display
{
public :
	void print(parking & garage)
	{
		for (size_t i = 5; i < 10; i++)
		{
			
			s = garage.getSlot(i);
			int x = s.getFull();
			if (x == 1)
			{
				cout << i + 1 << "->" << "$" << endl;
			}
			else
			{
				cout << i + 1 << "->" << "_" << endl;
			}
		}
	}
};
class onwercontrler
{
private :
	owner o;
public :
	onwercontrler(){}
	void controlOwner(string p, string m)
	{
		o.setPhoneNumber(p);
		o.setMail(m);
	}
	owner getOwner()
	{
		return o;
	}
};
class vehiclecontroler
{
private:
	vehicle car;
public:
	void setCarInf(string n, string i, int y, int l, int w,owner obj)
	{
		car.setModelName(n);
		car.setModelYear(y);
		car.setId(i);
		car.setLength(l);
		car.setWidth(w);
		car.setOwner(obj);
	}
	vehicle getCar()
	{
		return car; 
	}
	

};

class selectionbehaviour
{

public:
	slot temp;
	int index;
	virtual void selectSlot(int l, int w, parking& garage, vehicle& car) = 0;
};
class firstFitBehaviour : public selectionbehaviour
{
public:
	void selectSlot(int l, int w, parking& garage, vehicle& car)
	{
		for (size_t i = 0; i < 10; i++)
		{
			slot s = garage.getSlot(i);
			if (s.getFull() == 0 && l <= s.getLength() && w <= s.getWidth())
			{
				s.setFull(1);
				s.setCar(car);
				garage.setSlot(i, s);
				index = i;

				break;
			}

		}
	}
};
class bestFitBehaviour : public selectionbehaviour
{
public:
	void selectSlot(int l, int w, parking& garage, vehicle& car)
	{
		if (l > 180 || w > 100)
		{
			for (size_t i = 0; i < 5; i++)
			{
				slot s = garage.getSlot(i);
				if (s.getFull() == 0 && l <= s.getLength() && w <= s.getWidth())
				{
					temp.setFull(1);
					temp.setCar(car);
					garage.setSlot(i, temp);
					index = i;
					break;
				}
			}
		}
		else
		{
			for (size_t i = 5; i < 10; i++)
			{
				slot s = garage.getSlot(i);
				if (s.getFull() == 0 && l <= s.getLength() && w <= s.getWidth())
				{
					temp.setFull(1);
					temp.setCar(car);
					garage.setSlot(i, temp);
					index = i;
					break;
				}

			}
		}

	}
};
class selection
{
protected:
	selectionbehaviour* s;
public:
	selection() {}
	bool cehckDimensions(int l, int w)
	{
		bool status = true;
		if (l > 200)
		{
			status = false;
		}
		if (w > 120)
		{
			status = false;
		}
		return status;

	}
	int returnIndex()
	{
		return s->index;
	}
	virtual void slotSelection(int l, int w, parking& garage, vehicle& car) = 0;
};
class firstfit : public selection
{
public:
	firstfit() {}
	void slotSelection(int l, int w, parking& garage, vehicle& car)
	{
		s = new firstFitBehaviour();
		s->selectSlot(l, w, garage, car);
	}
};
class bestfit : public selection
{
public:
	void slotSelection(int l, int w, parking& garage, vehicle& car)
	{
		s = new bestFitBehaviour();
		s->selectSlot(l, w, garage, car);
	}
};
class totalincome
{
private:
	int totalfees;
public:
	totalincome()
	{
		totalfees = 0;
	}
	void setTotalFess(int f)
	{
		totalfees += f;
	}
	int getTotalfees()
	{
		return totalfees;
	}

};

class fees
{
public:
	virtual int calculateFees(int total )  = 0;
	
};
class bigslotsfees : public fees
{
public :
	int calculateFees(int total )
	{
		int fees;
		fees =total * 10;
		return fees;
	}
};
class smallslotsfees : public fees
{
public :
	int calculateFees(int total )
	{
		int fees;
		fees= total * 5;
		return fees;
	}

};

class observers
{
public:
	virtual void update() = 0;
};
class subject
{
protected :
	observers *arraylist[10];
public :
	virtual void addObserver(observers *obj ,int index ) = 0;
	virtual void removeObserver( int index) = 0;
	virtual void  notifyingObserver(int index) = 0;
};
class receipt : public subject
{
private:
	timee onwertime;
	int cost;
public:

	void addObserver(observers *obj , int index)
	{

		arraylist[index] = obj;
	}
	void removeObserver( int index )
	{
		arraylist[index] = NULL;
	}
	void setTime(timee obj)
	{
		onwertime = obj;
	}
	void setCost(int obj)
	{
		cost = obj;
	}
	void  notifyingObserver( int index )
	{
			arraylist[index]->update();
	}
	int getHoursIn()
	{
		return onwertime.getTimeInH();
	}
	int getHoursOut()
	{
		return onwertime.getTimeOutH();
	}
	int getMinIn()
	{
		return onwertime.getTimeInm();
	}
	int getMinOut()
	{
		return onwertime.getTimeOutM();
	}
	int getCost()
	{
		return cost;
	}

};

class messageDisplay
{
public :
	virtual void displayMessage() = 0;
};
class smsDisplay : public observers , messageDisplay
{
private :
	int hoursIn;
	int hoursOut;
	int minIn;
	int minOut;
	int cost;
	receipt owner;
public :
	smsDisplay(receipt  &obj)
	{
		owner = obj;
	}
	void update()
	{
		hoursIn = owner.getHoursIn();
		hoursOut = owner.getHoursOut();
		minIn = owner.getMinIn();
		minOut = owner.getMinOut();
		cost = owner.getCost();

	}
	void displayMessage()
	{
		cout << "the arrival time =" << hoursIn << ":" << minIn << endl; 
		cout << "the departure time =" <<hoursOut << ":"<< minOut << endl;
		cout << "parking cost = " << cost << endl;
		cout << " sending by {sms} " << endl;
	}
};
class mailDisplay : public observers, messageDisplay
{
private :
	int hoursIn;
	int hoursOut;
	int minIn;
	int minOut;
	int cost;
	receipt owner;
public :
	mailDisplay(receipt  &obj)
	{
		owner = obj;
	}
	void update()
	{
		hoursIn = owner.getHoursIn();
		hoursOut = owner.getHoursOut();
		minIn = owner.getMinIn();
		minOut = owner.getMinOut();
		cost = owner.getCost();

	}
	void displayMessage()
	{
		cout << "the arrival time =" << hoursIn << ":" << minIn << endl;
		cout << "the departure time =" << hoursOut << ":" << minOut << endl;
		cout << "parking cost = " << cost << endl;
		cout << " sending by {mail} " << endl;
	}
};

class timemanagment 
{
private :
	timee z; 
	slot s;

public :

	bool checkTime(int m, int h)
	{
		bool status = true;
		if (m > 59 || m < 0)
		{
			return false;
		}
		if (h > 23 || h < 0)
		{
			return false;
		}
		return status;
		
	}
	void parkIn(int m, int h , parking& garage   , int l , int w , selection & select ,vehicle& car)
	{
		        select.slotSelection(l, w, garage, car);
				int temp = select.returnIndex();
				s = garage.getSlot(temp);
				z.setTimeInH(h);
				z.setTimeInm(m);
				s.setTime(z);
				garage.setSlot(temp,s);
	}
	int parkOut(int m, int h,  int index , int day, fees & obj , parking & garage )
	{   
	    s = garage.getSlot(index);
		z = s.getTime();
		z.setTimeOutH(h);
		z.setTimeOutM(m);
		int h_in = z.getTimeInH();
		int m_in = z.getTimeInm();
		int diff;
		int fees;
		if (s.getFull() != 0)
		{

			if (day == 0)
			{
				if (h_in > h)
				{
					diff = 0;
					fees = obj.calculateFees(diff);
				}
				else if (h_in < h)
				{

					diff = h - h_in;
					if (m > m_in)
					{
						diff++;
					}
					fees = obj.calculateFees(diff);
				}
				else if (h_in = h)
				{
					diff = 1;
					fees = obj.calculateFees(diff);
				}
			}
			else
			{
				if (h_in > h)
				{
					int tmp = h_in - h;
					diff = (day * 24) - tmp;
					if (m > m_in)
					{
						diff++;
					}
					fees = obj.calculateFees(diff);
				}
				else if (h_in < h)
				{
					int tmp = h - h_in;
					diff = (day * 24) + tmp;
					if (m > m_in)
					{
						diff++;
					}
					fees = obj.calculateFees(diff);
				}
				else if (h_in = h)
				{
					
					diff = (day * 24);
					if (m > m_in)
					{
						diff++;
					}
					fees = obj.calculateFees(diff);
				}
			}
		}
		else
		{
			return -1;
		}
			return fees;
	}
	timee getAllTimeDetails()
	{
		return z;
	}
};

class deletion
{
private :
	vehicle emptyCar;
	slot emptySlot;
	timee emptyTime; 
public :
	deletion(){}
	void clearSlot(parking& garage, int index)
	{
		emptySlot = garage.getSlot(index);
		emptySlot.setFull(0);
		emptySlot.setCar(emptyCar);
		emptySlot.setTime(emptyTime);
		garage.setSlot(index , emptySlot);
	}
};
class interaction
{
private :
	parking p;
	totalincome total;
	receipt x;
public :
	void interact()
	{
		int keep = 1;
		concereteParkingBuilder b;
		b.setParking(p);
		concereteParkingBuilder* ptr;
		ptr = &b;
		parkingdirector d(ptr);
		p = d.construct();
		int carcounter = 0;

		while (keep == 1)
		{
			cout << "big slots = 10 EGP Per hour " << endl;
			cout << "small slots = 5 EGP Per hour " << endl;
			cout << "*********" << endl;
			cout << "1 ->enter" << endl;
			cout << "2 -> get out" << endl;
			cout << "3-> display big diminsions " << endl;
			cout << "4-> display small diminsions" << endl;
			cout << "5-> get total income " << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				checksize size;
				if (!size.checkmax(p))
				{
					cout << " enter the name of the vehicle " << endl;
					string name;
					cin >> name;

					cout << " enter the id of the vehicle " << endl;
					string id;
					cin >> id;

					cout << " enter the model year of the vehicle" << endl;
					int model;
					cin >> model;

					cout << " enter the length of the vehicle" << endl;
					int length;
					cin >> length;

					cout << " enter the width of the vehicle " << endl;
					int width;
					cin >> width;
                    owner owner;

					cout << " enter your phone number " << endl;
					string phone;
					cin >> phone;

					cout << " enter your mail " << endl;
					string mail;
					cin >> mail;

					onwercontrler o;
					o.controlOwner(phone, mail);
					owner = o.getOwner();
					vehiclecontroler save;
					save.setCarInf(name, id, model, length, width,owner);
					vehicle car = save.getCar();

					timemanagment t;
					cout << " enter time in in hours " << endl;
					int h;
					cin >> h;

					cout << " enter time in in min " << endl;
					int m;
					cin >> m;


					if (t.checkTime(m, h))
					{
						cout << " 1-> select by first fit" << endl;
						cout << " 2-> select by bets fit" << endl;
						int fitchoice;
						cin >> fitchoice;
						if (fitchoice == 1)
						{

							firstfit first;
							bool status = first.cehckDimensions(length, width);
							if (status == 1)
							{
								t.parkIn(m, h, p, length, width, first, car);
								cout << "park in is done " << endl;
								cout << " yous slot number is :" << first.returnIndex() + 1 << endl;
								carcounter++;
							}
							else
							{
								cout << " your vehicle size is not accpetable here " <<  endl;
							}
						}
						else if (fitchoice == 2)
						{
							bestfit best;
							bool status = best.cehckDimensions(length, width);
							if (status == 1)
							{
								t.parkIn(m, h, p, length, width, best, car);
								cout << "park in is done " << endl;
								cout << " yous slot number is :" << best.returnIndex() + 1 << endl;
								carcounter++;
							}
							else
							{
								cout << " your vehicle size is not accpetable here " << endl;
							}
						
						}
						else
						{
							cout << "there is no option with this number " << endl;
						}
					}
					else
					{
						cout << "there is a problem in time submission" << endl;
					}

				}
				else
				{
				  cout << "sorry garage is full " << endl;
				}
			}
			else if (choice == 2)
			{
				int keep2 = 1;
				if (carcounter != 0)
				{
					while (keep2 == 1)
					{
						cout << " enter your slot number" << endl;
						int index;
						cin >> index;
						index = index--;
						cout << "****please notice that the programm work with 24 hours format****" << endl;
						cout << " enter the time out (hours)" << endl;
						int h;
						cin >> h;
						cout << " enter the time out (min)" << endl;
						int m;
						cin >> m;
						cout << " enter the number of days " << endl;
						int dayNum;
						cin >> dayNum;
						
						timemanagment t;
						deletion d;
						if (index < 0 || index >9)
						{
							cout << " there is no slot with this number in the garage " << endl;
							break;
						}
						if (t.checkTime(m, h))
						{
							if (index <= 4)
							{
								bigslotsfees big;
								int tmp = t.parkOut(m, h, index, dayNum, big, p);
								timee time = t.getAllTimeDetails();
								x.setTime(time);
								x.setCost(tmp);
								cout << "1-> sms" << endl;
								cout << "2-> mail" << endl;
								int notify_choice;
								cin >> notify_choice;
								if (notify_choice == 1)
								{
									smsDisplay sms(x);
									smsDisplay* ptr = &sms;
									x.addObserver(ptr, index);
									x.notifyingObserver(index);
									sms.displayMessage();
									x.removeObserver(index);
								}
								else if (notify_choice == 2)
								{
									mailDisplay m(x);
									mailDisplay* ptr = &m;
									x.addObserver(ptr, index);
									x.notifyingObserver(index);
									m.displayMessage();
								}
								
								total.setTotalFess(tmp);
								d.clearSlot(p, index);
								carcounter--;
								if (tmp == -1)
								{
									cout << " this index is already empty" << endl;
								}
								else
								{
									keep2 = 0;
								}
								if (tmp == 0)
								{
									cout << " wrong submission to time out" << endl;
								}
								else
								{
									keep2 = 0;
								}
							}
							else if (index > 4)
							{
								smallslotsfees small;
								
								
								int tmp = t.parkOut(m, h, index, dayNum, small, p);
						
								d.clearSlot(p, index);
								carcounter--;
								if (tmp == -1)
								{
									cout << " this index is already empty" << endl;
								}
								else
								{
									keep2 = 0;
								}
								if (tmp == 0)
								{
									cout << " wromg submission to time out" << endl;
								}
								else
								{
									keep2 = 0;
								}
							}
						}
					}
				}
				else
				{
					cout << " there no vehicles in the parking to get out" << endl;
				}
			}
			else if (choice == 3)
			{
				displaybigslots big;
				big.print(p);
			}
			else if (choice == 4) 
			{
			    displaysmallslots small;
				small.print(p);
			}
			else if (choice == 5)
			{
			  cout << "total income of the parking is :" << total.getTotalfees() << endl;
			}
		}
	}


 };
int main()
{
	interaction x; 
	x.interact();

	
	
	


	

	
	
	
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
