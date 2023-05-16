<?php 
session_start();
include '../connexion_BD/connexion.php';
if(isset($_SESSION['id']))
{
    if(isset($_GET['idClient']))
    {   $utl=$_GET['idClient'];

        $req="exec  ps_supprimer_Utilisateur_Client '$utl'";  

        $res = sqlsrv_query($conn,$req);
        header("Location: Clients.php");
    }
    if(isset($_GET['idArticle']))
    {
        $art=$_GET['idArticle'];

        $req="exec ps_supprimer_Article '$art'";  

        $res = sqlsrv_query($conn,$req);
        header("Location: Articles.php");
    }
    if(isset($_GET['idComment']))
    {
        $cmnt=$_GET['idComment'];

        $req="exec ps_supprimer_Commentaire'$cmnt'";  

        $res = sqlsrv_query($conn,$req);
        header("Location: Commentaires.php");
    }
   
}
else {
    header("Location: ../index.php");
}

?>