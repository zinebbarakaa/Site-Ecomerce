<?php 
session_start();
include "connexion_BD/connexion.php";
include "panier.class.php";
$panier=new panier();
if(isset($_GET['id']) && isset($_SESSION['id']))
{	$art=$_GET['id'];
	$utl=$_SESSION['id'];
	$panier->add($_GET['id']);
	
	if($_SESSION['panier'][$art]>0)
	{
		$req="exec ps_Ajouter_Article_au_panier '$utl','$art',1";

		$params = array();
		$options =  array( "Scrollable" => SQLSRV_CURSOR_KEYSET );
		$res = sqlsrv_query($conn,$req);
		$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
		if(!empty($row))
		{
			header("Location: panier.php?erreur=".$row['msg']);
		}
		else 
		{
			header("Location: panier.php");
		}

	}
	
}
else 
{
	die("vous n'avez pas selectionné de produit à ajouter au panier");
}
?>

