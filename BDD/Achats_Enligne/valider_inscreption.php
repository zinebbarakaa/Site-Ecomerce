<?php

include "connexion_BD/connexion.php";
if(isset($_POST['submit']))
	{ 
		
		$nom=htmlentities(trim($_POST['nom']));
		$prenom=htmlentities(trim($_POST['prenom']));
		$email=htmlentities(trim($_POST['email']));
		$adresse=htmlentities(trim($_POST['adresse']));
		$tel=htmlentities(trim($_POST['tele']));
		$date_naiss=htmlentities(trim($_POST['date_naiss']));
		$pass=htmlentities(trim($_POST['pass']));
		$passc=htmlentities(trim($_POST['passc']));	

		if($pass==$passc)
		{
			$req="exec ps_inscreption_Client '$nom','$prenom','$email','$date_naiss','$adresse','$tel','$pass'";
			$res=sqlsrv_query($conn,$req);	

			header("Location: connecter.php");

		}
		else
		{
			header("Location: inscreption.php");
		}
					
}
	

	

?>