static uint8_t mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
/*adresse mac coller sous le shield ou celle ci par defaut */
EthernetClient client;
/* créé un objet client representant la conection */


Ethernet.begin(mac);
/* Configuration de la bibliothèque Ehternet avec l'adresse mac il est optinel de placer l'adresse ip et autre réglage car depuit IDE 1.0 la biblioteque prend en charge le DHCP*/

void alertemail(){

   char server [] = "uhack.me"; //votre site internet perso exemple celui de mon site free
    Serial.println("adresse ip : ");//on demande au serial d'aficher l'adresse ip atribure par le DHCP
    Serial.println(Ethernet.localIP());
    delay(1000);
    Serial.println("connection...");
    for( byte i=1;i<=3;i++){
      switch(i){
        case 1 :
if (client.connect(server, 80)) {
    Serial.println("conexion avec le server etabli");
    // requête HTTP ver une page PHP sur le serveur de votre site:
    client.println("GET /get/temperature/temp.php?alerte=1 HTTP/1.1");/* on va faire une requete de type get pour demander au serveur d'exécuter le code PHP de la page alertetemp.php alerte = 1 pour le premier type de message*/
    client.println("Host: uhack.me");
     client.println("User-Agent: arduino-ethernet");
   client.println("Connection: close");
    client.println();
    }else {
    Serial.println("echec de la conection");};//si la connection n'a pas réussi:
    break;
    case 2:
    Serial.println(" lecture reponse client");
    delay(5000);
    Serial.print(" nombre de byte disponible : ");
    Serial.println(client.available());//on demande l'affichage du nombre de byte disponible
if(client.available()) {//on demande l'affichage de la réponse client
  for( int i=0;i<=client.available();i++){
       char c= client.read();
       Serial.print(c);
       }
       Serial.println();
       delay(1000);
  Serial.println("vide du tampon client");
  client.flush();//on vide la mémoire tampon du client
};
break;
  case 3:
  Serial.println("tentative de deconection");
   if (!client.connected()) {
    Serial.println();
    Serial.println("deconection.");
    client.stop();//on déconnecte et termine la liaison avec le client

};
break;};}
return;}
