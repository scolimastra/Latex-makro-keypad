/*  Latex makro Keypad by Scolimastra
 *  
 *  Probably due to incompatibility with QWERTZ layout many Keys are switched: *  
 *  The write function seems to be faster then print so when using them after eachother a delay(50) is needed
 *  
 *  A few uses that I found:
 *  
 *  ALT(45);                   \ (backslach)
 *  Keyboard.write(63);        _ (underscore)
 *  Keyboard.write(96); (x2)   ^ (caret)
 *  Keyboard.write(125);       * (asterisk)
 *  ALT('7');                  { (left brace)
 *  ALT('0');                  } (right brace)
 *  ALT('8');                  [ (left bracket)
 *  ALT('9');                  ] (right bracket)
 *  write(10);                 return
 *  write(11);                 tab
 *  write(127);                backspace
 */

#include <Keypad.h>

char prev = ' ';
boolean item = false;

const byte ROWS = 5; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
//ignore the tilted layout I soldered first and then programmed...
char hexaKeys[ROWS][COLS] = {
  {'4','9','E','J'},
  {'3','8','D','I'},
  {'2','7','C','H'},
  {'1','6','B','G'},
  {'0','5','A','F'}
};
byte rowPins[ROWS] = {0, 1, 2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 6, 7, 8}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {

}

void loop() {
  char customKey = customKeypad.getKey();
  switch(customKey){
    case '0':                             //enumerate environment with \item with duplicate presses
      if(prev == customKey && !item){
        item = true;
        Keyboard.write(10);
        ALT(45);
        Keyboard.print("item");
      }else if(prev == customKey && item){  //random bug that enter need to be pressed twice after the first time
        Keyboard.write(10);
        Keyboard.write(10);
        ALT(45);
        Keyboard.print("item");
      }else{
        item = false;
        ALT(45);       
        Keyboard.print("begin");       
        ALT('7');       
        Keyboard.print("enumerate");       
        ALT('0');       
        ALT('8');       
        Keyboard.print("label)");       
        ALT(45);
        Keyboard.print("alph");       
        Keyboard.write(125);       
        Keyboard.write(40);       
        ALT('9');       
        Keyboard.write(10);
        Keyboard.write(11);
        delay(5);
        ALT(45);
        Keyboard.print("item");
        Keyboard.write(10); 
        Keyboard.write(127);
        ALT(45);       
        Keyboard.print("end");       
        ALT('7');       
        Keyboard.print("enumerate");       
        ALT('0');
      }
      prev = customKey;
      break;  
          
    case '1':                     //align* environment
      ALT(45);       
      Keyboard.print("begin");       
      ALT('7');       
      Keyboard.print("align");
      Keyboard.write(125);      
      ALT('0');   
      Keyboard.write(10);
      Keyboard.write(10);       
      ALT(45);       
      Keyboard.print("end");       
      ALT('7');       
      Keyboard.print("align");
      Keyboard.write(125);        
      ALT('0');
//      Keyboard.write(KEY_UP_ARROW);
      prev = customKey;
      break;   
       
    case '2':                     //<=
      ALT(45);       
      Keyboard.print("Leftarrow ");
      prev = customKey;
      break;   
       
    case '3':                     //<=>
      ALT(45);       
      Keyboard.print("Leftrightarrow ");
      prev = customKey;
      break;  
        
    case '4':                     //=>
      ALT(45);       
      Keyboard.print("Rightarrow ");
      prev = customKey;
      break;   
       
    case '5':                     // \forall
      ALT(45);       
      Keyboard.print("forall ");
      prev = customKey;
      break;  
        
    case '6':                     // \exists
      ALT(45);       
      Keyboard.print("exists ");
      prev = customKey;
      break;    
      
    case '7':                     // \in
      ALT(45);         
      Keyboard.print("in ");
      prev = customKey;
      break;    
      
    case '8':                     // \equiv
      ALT(45);       
      Keyboard.print("equiv ");
      prev = customKey;
      break;   
       
    case '9':                     // \[\]
      ALT(45);       
      ALT('8');       
      ALT(45);       
      ALT('9');
      prev = customKey;
      break;    
      
    case 'A':                     // \sum_{}^{}
      ALT(45);       
      Keyboard.print("sum");
      delay(50);    
      Keyboard.write(63);
      ALT('7');       
      ALT('0');    
      delay(50);   
      Keyboard.write(96);
      Keyboard.write(96);  
      delay(5);     
      ALT('7');       
      ALT('0');
      prev = customKey;
      break;
          
    case 'B':                     // \lim_{}
      ALT(45);       
      Keyboard.print("lim");       
      Keyboard.write(63);       
      ALT('7');       
      ALT('0');
      prev = customKey;
      break;   
       
    case 'C':                     // \frac{}{}
      ALT(45);       
      Keyboard.print("frac");       
      ALT('7');       
      ALT('0');       
      ALT('7');       
      ALT('0');
      prev = customKey;
      break;  
        
    case 'D':                     // \sqrt{}
      ALT(45);       
      Keyboard.print("sqrt");       
      ALT('7');       
      ALT('0');
      prev = customKey;
      break;
          
    case 'E': // \left( \right)
      ALT(45);       
      Keyboard.print("left");       
      SHIFT('8');       
      Keyboard.print("  ");       
      ALT(45);       
      Keyboard.print("right");
      SHIFT('9');
      prev = customKey;
      break;  
        
    case 'F':                     // \varphi
      ALT(45); 
      Keyboard.print("varphi ");
      prev = customKey;
      break;   
       
    case 'G':                     // \psi
      ALT(45); 
      Keyboard.print("psi ");
      prev = customKey;
      break;  
        
    case 'H':                     // \delta
      ALT(45); 
      Keyboard.print("delta ");
      prev = customKey;
      break;   
       
    case 'I':                     // \varepsilon
      ALT(45); 
      Keyboard.print("varepsilon ");
      prev = customKey;
      break;  
        
    case 'J':                     // \cdot
      ALT(45); 
      Keyboard.print("cdot ");
      prev = customKey;    
      break;
  }
}

// Alt + key funtion
void ALT(int i){
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.press(i);
  Keyboard.release(i);
  Keyboard.release(KEY_RIGHT_ALT);
}

// Shift + key funtion
void SHIFT(int i){
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(i);
  Keyboard.release(i);
  Keyboard.release(KEY_LEFT_SHIFT);
}

// Ctrl + key funtion
void CTRL(int i){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(i);
  Keyboard.release(i);
  Keyboard.release(KEY_LEFT_CTRL);
}
