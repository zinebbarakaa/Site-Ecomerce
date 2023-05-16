<?php
	include '../connexion_BD/connexion.php';
	 
          if(isset($_POST['submit']) && isset($_GET['idArticle']))
    {


       $art=$_GET['idArticle'];
       $desg=htmlentities(trim($_POST['desg']));
       $desc=htmlentities(trim($_POST['desc']));
       $type=htmlentities(trim($_POST['type']));
       $col=htmlentities(trim($_POST['couleur']));
       $taille=htmlentities(trim($_POST['taille']));
       $prix=htmlentities(trim($_POST['prix']));
       $QtStock=htmlentities(trim($_POST['QtStock']));
       $ImgP=htmlentities(trim($_POST['ImgP']));
       $ImgS1=htmlentities(trim($_POST['ImgS1']));
       $ImgS2=htmlentities(trim($_POST['ImgS2']));

       $req="exec ps_Modifier_Article_par_Admin '$art','$type','$desg','$desc','$taille','$col','$prix',
            '$QtStock','$ImgP','$ImgS1','$ImgS2'";
        $res=sqlsrv_query($conn,$req);
         header("Location: Articles.php");
        
        

    }

?>