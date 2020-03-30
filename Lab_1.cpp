#include <iostream>   //#include <iostream.h>, C stils
#include <conio>      //#include <conio.h>, C stils

/*    Strings: C++ stils    */
//#include <string>
//using namespace std;

class CoordPoint {
   private:
      int X;
      int Y;
   public:
      CoordPoint();
      CoordPoint(int, int);
      ~CoordPoint() {
         cout << "Message from the \"CoordPoint\" - destroyed!" <<
           endl;
      }
      int GetX() const {
         return X;
      }
      void SetX(int X) {
         this->X = X;
      }
      int GetY() const;
      void SetY(int);
      void Print() const;
};

CoordPoint::CoordPoint() : X(0), Y(0) {
}

CoordPoint::CoordPoint(int Px, int Py) : X(Px) {
   Y = Py;
}
inline int CoordPoint::GetY() const {
   return Y;
}
inline void CoordPoint::SetY(int Y) {
   this->Y = Y;
}
inline void CoordPoint::Print() const {
   cout << "X = " << X << ", Y = " << Y;
}

void main(void) {
   CoordPoint CP1, CP2(1,2), CP3 = CoordPoint(3, 4),
     *CP4 = new CoordPoint(5, 6), *CP5;
   CP5 = new CoordPoint(7, 8);

   clrscr();

   CP1.Print();cout<<endl;
   CP1.SetX(1);
   CP1.CoordPoint::Print();cout<<endl;

   cout << endl << "**************" << endl << endl;

   (*CP4).Print();cout<<endl;
   CP4->SetY(9);
   CP4->Print();cout<<endl;
   (*CP4).CoordPoint::Print();cout<<endl;
   CP5->CoordPoint::Print();cout<<endl;

   delete CP4;
   delete CP5;

/* Aizture: C stils */
   while (kbhit()) // C stils
      getch();     // C stils
   getch();        // C stils

/* Aizture: C++ stils */
// cin.get();
}
