<?php
session_start();
include "connexion_BD/connexion.php";
if($_POST['submit'] && isset($_SESSION['id']) && isset($_SESSION['Adresse']) && isset($_SESSION['Ville']))
{
	
	$utl=$_SESSION['id'];
	$paiment=htmlentities(trim($_POST['Paiment']));
	
	$ville=$_SESSION['Ville'];
	$Adresse=$_SESSION['Adresse'];
	
	$req="exec ps_paiement_Client '$utl','$paiment','$ville','$Adresse'";
	$res=sqlsrv_query($conn,$req);

	
	header("Location: home.php");
}
?>