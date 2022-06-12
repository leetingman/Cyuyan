#include "Student.h"


struct Student{
    char name[20];
    int finalScore,classScore,scholaship;
    bool isOfficer,isWest,isThesis;
};

int fellowship(struct Student *stu){
  if(stu->finalScore>85&&stu->isThesis) return 8000;
  return 0;
}
int wusiScholaship(struct Student *stu){
  if(stu->finalScore>85&&stu->classScore>80) return 4000;
  return 0;
}
int scoreScholaship(struct Student *stu){
  if(stu->finalScore>90) return 2000;
  return 0;
}
int westScholaship(struct Student *stu){
  if(stu->classScore>85&&stu->isWest) return 1000; 
  return 0;
}
int classOfficerScholaship(struct Student *stu){
  if(stu->classScore>80&&stu->isOfficer) return 850;
  return 0;
}
int sumScholaship(struct Student *stu){
  // sum scholaship method 
  int sum=0;
  sum += fellowship(stu);
  sum += wusiScholaship(stu);
  sum += scoreScholaship(stu);
  sum += westScholaship(stu);
  sum += classOfficerScholaship(stu);
  return sum;
}

void inputData(struct Student *stu,int students){
    int paper;
    char flag;
    int i;
    for(i=0;i<students;i++){
        int scholaship=0;
        printf("");
        printf("Input name:");
        scanf("%s",&stu->name);
        printf("Input final score:");
        scanf("%d",&stu->finalScore);
        printf("Input class score:");
        scanf("%d",&stu->classScore);
        while(1){
        printf("Class officer or not(Y/N):");
        scanf(" %c",&flag);
        printf("%c",flag);
        if(flag=='y'||flag=='n') break;
        printf("please input y or n");
        }
        flag=' ';
        if(flag=='y') {stu->isOfficer=true;}
        else {stu->isOfficer=false;}
        while(1){
        printf("Students from the West or not(Y/N):");
        scanf(" %c",&flag);
        if(flag=='y'||flag=='n') break;
        printf("please input y or n");
        }
        if(flag=='y')stu->isWest=true;
        else stu->isWest=false;  
        printf("Input the number of published papers:");
        scanf(" %d",&paper);
        if(paper>0)stu->isThesis=true;
        else stu->isThesis=false;
        //scholarship  
        scholaship=sumScholaship(stu);
        stu->scholaship=scholaship;
        //next 
        stu++;
      }
  }

struct Student*  Process(struct Student s[],int students) {
    int i, j;
    struct Student temp;
    bool b;
    for (i = 0; i < students; i++) {
        for (j = i + 1; j < students; j++) {
            if (s[i].scholaship < s[j].scholaship) {         
              //name
              strcpy(temp.name, s[i].name);
              strcpy(s[i].name, s[j].name); 
              strcpy(s[j].name, temp.name);
              //final
              temp.finalScore =s[i].finalScore;
              s[i].finalScore  =s[j].finalScore;
              s[j].finalScore =temp.finalScore;
              //class
              temp.classScore =s[i].classScore;
              s[i].classScore =s[j].classScore;
              s[j].classScore=temp.classScore;
              //officer
              b = s[i].isOfficer;
              s[i].isOfficer= s[j].isOfficer;
              s[j].isOfficer= b;
              //paper
              b = s[i].isThesis;
              s[i].isThesis= s[j].isThesis;
              s[j].isThesis= b;
              //west
              b = s[i].isWest;
              s[i].isWest= s[j].isWest;
              s[j].isWest= b;  
            }
        }
    }
    return s;
}

void outputData(struct Student *s,int students) {
    int i;
    for (i = 0; i < students; i++) {
        printf("name: %s \n",s[i].name);
        printf("class score: %d \n",s[i].classScore);      
        printf("final score: %d \n",s[i].finalScore);
        s++; 
    }
    printf("schcolaship king is who? = > :%s %d",s[0].name,s[0].scholaship);
}

void main(void) {
    //students
    int students;
    printf("putin number of students :\n");
    scanf("%d",&students);
    // init
    struct Student s[students];
    // input data
    inputData(s,students);  
    // sort data
    memcpy(s, (struct Person*)Process(s,students), sizeof(s)); 
    // output data
    outputData(s,students); 
}
