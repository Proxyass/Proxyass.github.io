<?php

if ($_GET['alerte']=="1") {
     // Le message
     $message = "Température est chaude";

     // Dans le cas où nos lignes comportent plus de 70 caractères, nous les coupons en utilisant wordwrap()
     $message = wordwrap($message, 70);

     // Envoi du mail

	 $envoi=mail("ermal.a14@hotmail.com",'alerte', $message,"From: $exp\r\n"."Reply-To: $exp\r\n");
if($envoi) echo"Le mail a bien été envoyé !";
else echo"L'envoi a échoué, merci de renouveller l'opération !"; };
?>
