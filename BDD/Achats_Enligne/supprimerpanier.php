<?php 
session_start();
include "connexion_BD/connexion.php";
include "panier.class.php";
$panier=new panier();
if(isset($_GET['id']) && isset($_SESSION['id']))
{	$art=$_GET['id'];
	$utl=$_SESSION['id'];
	$panier->del($_GET['id']);
	
	if($_SESSION['panier'][$art]>=0)
	{
		$req="exec ps_diminier_QtCmd_Article '$utl','$art',1";
		$res=sqlsrv_query($conn,$req);

	}
	header("Location: panier.php");
}
else 
{
	die("vous n'avez pas selectionné de produit à ajouter au panier");
}
?>