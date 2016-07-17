// EM-18 Module based RFID Door lock
// 17-07-2016 3:33 am
//  for complete instructions visit my site
// www.KartikNighania.com feel free to contact for any help

short inputChars ;               // number of inputChars characters
char ID[12];                     //  ID of card/key tag
                                   
void setup()
{
   Serial.begin(9600);           // open serial with baud 9600
}
void loop()
{

   if(Serial.available()) //READ ID
   {
      inputChars = 0;
      while(Serial.available() && inputChars < 12)    //EM-18 gives 10 id char + 2 error check char     
      {
         ID[inputChars] = Serial.read();
         inputChars++;
         delay(10);
      }
      Serial.flush();
      Serial.print(ID);   //PRINT ID  

       // EM-18 gives last two char for error check ( Ex-OR of all five two digit numbers of ID) 
      
      if  ((ID[0] ^ ID[2] ^ ID[4] ^ ID[6] ^ ID[8] == ID[10]) &&  (ID[1] ^ ID[3] ^ ID[5] ^ ID[7] ^ ID[9] == ID[11]))
      {
            Serial.println(" Read Successful ");
      }
      
      else
            Serial.println("Checksum Error");      
   }
}
