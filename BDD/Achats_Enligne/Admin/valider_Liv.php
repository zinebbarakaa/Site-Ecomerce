<?php 
session_start();
include '../connexion_BD/connexion.php';
if(isset($_POST['submit']) && isset($_GET['idfacture']))
{
	$date=$_POST['date'];
	$fact=$_GET['idfacture'];
	$req="exec ps_Valider_Livraison '$fact','$date'";
    $res=sqlsrv_query($conn,$req);
    header("Location: index.php");
}


 ?>