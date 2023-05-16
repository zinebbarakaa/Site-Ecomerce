<?php
session_start();
include "connexion_BD/connexion.php";
	if(isset($_POST['submit']) && $_SESSION['id'])
		{	
			
			$art=$_GET['idArticle'];
			$utl=$_SESSION['id'];
			$cmnt=htmlentities(trim($_POST['comt']));
			$req="exec ps_Ajouter_Commentaire '$utl','$art','$cmnt'";
			$res=sqlsrv_query($conn,$req);
			header("Location: Fiche_Article.php?IdArticle=".$art);
			
			
		}

?>