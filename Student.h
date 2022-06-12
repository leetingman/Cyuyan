#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//-----------------------------------------------------------
/*
  Struct Student
  기말 평균 — finalScore , 
  반평균 -- classScore,
  간부 여부 — isOfficer,
  서부 여부 — isWest
  논문 여부 — isThesis

  local
  학생 총 수 -- studentNum
*/
//-----------------------------------------------------------



// typedef struct student{
//     char name[20];
//     int finalScore,classScore;
//     bool isOfficer,isWest,isThesis;
// }Student;


// int studentNum;

// Student* stu;




/*
变数
：
기말 평균 — finalScore , 
반평균 -- classScore,
간부 여부 — isOfficer,
서부 여부 — isWest
논문 여부 — isThesis



Function fellowShip
finalScore > 80
isThesis=ture;
Scholarship ==8000

Function  wusiScholaship
finalScore > 85,
classScore>80
Scholarship 4000

Function scoreScholaship
finalScore >90
Scholarship 2000

Function westScholaship
classScore > 85 
isWest
Scholarship 1000

Function classOfficerScholaship
classScore > 80
isOfficer=true
Scholarship 850

If finalScore =87, classScore = 82 , isOfficer =true

Scholarship = 4850



*/