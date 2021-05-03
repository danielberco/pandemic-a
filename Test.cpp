
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace pandemic;
   
    

    TEST_CASE("Test Players Roles")
    {
        Board b;  
        b[City::Karachi] = 1;  //black     
        b[City::Istanbul] = 1;   //black
        b[City::Lagos] = 2; //yellow
        b[City::Manila] = 2; //red   

        CHECK_FALSE(b.is_clean());
        CHECK_EQ(b[City::Karachi],b[City::Istanbul]);
        //CHECK_EQ(b[City::Lagos],b[City::Manila]);

        OperationsExpert p1 {b, City::Chicago};  
        p1.take_card(City::Khartoum)
              .take_card(City::Milan)
              .take_card(City::MexicoCity)
              .take_card(City::Bogota)
              .take_card(City::HongKong);


        CHECK_THROWS(p1.drive(City::Beijing)); 
        CHECK_NOTHROW(p1.fly_direct(City::MexicoCity)); 
        CHECK_NOTHROW(p1.build()); 


        Dispatcher p2 {b, City::Paris};  
        CHECK_NOTHROW(p2.fly_direct(City::Khartoum)); 


        Scientist p3 {b, City::Algiers,2};  
        p3.take_card(City::SanFrancisco)
              .take_card(City::Baghdad);
        CHECK_THROWS(p3.discover_cure(Color::Blue)); 
        p3.take_card(City::NewYork);
        CHECK_NOTHROW(p3.discover_cure(Color::Blue)); 


        Medic p4 {b, City::Madrid};  
        p4.treat(City::Madrid);
        CHECK(b[City::Madrid] == 0);

        Virologist p5 {b, City::Kolkata};  
        CHECK_THROWS(p5.treat(City::Kolkata)); 
        CHECK_THROWS(p5.treat(City::Madrid)); 
        p5.take_card(City::Madrid);
        CHECK_NOTHROW(p5.treat(City::Madrid)); 

        GeneSplicer p6 {b, City::SaoPaulo}; 
        p6.take_card(City::Moscow)
              .take_card(City::Bogota)
              .take_card(City::Essen)
              .take_card(City::StPetersburg)
              .take_card(City::Washington);
        CHECK_NOTHROW(p6.discover_cure(Color::Black)); 

        FieldDoctor p7 {b, City::Seoul};  
        b[City::Shanghai] = 2;
        p7.treat(City::Shanghai);
        CHECK_EQ(b[City::Shanghai],1);
        CHECK_NE(b[City::Shanghai],b[City::Istanbul]);
    }


    TEST_CASE("Board Test")
    {
        Board b1;  //testing emptey board
        CHECK(b1.is_clean() == true);
        
        Board b2; 
        b2[City::Karachi] = 1;      
        b2[City::Istanbul] = 1;   
        b2[City::Lagos] =2; 
        b2[City::Manila] = 2;
        CHECK_EQ(b2[City::Karachi],b2[City::Istanbul]);
        CHECK_EQ(b2[City::Lagos],b2[City::Manila]);
        b2[City::Lagos] = 1;
        CHECK_EQ(b2[City::Manila],b2[City::Lagos]);
        CHECK_FALSE(b2.is_clean());
    }