<?php 
session_start();
include '../connexion_BD/connexion.php';
if(isset($_SESSION['id']))
{
    
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
    <style type="text/css">
            nav {
                display: flex;
                flex-wrap: wrap;
                justify-content:space-between;
                padding: 20px;
                background-color: #fff;
                position: sticky;
                top: 0;

            }
        nav h1 {
            font-size: 20px;
        }   
        nav .ong{
            display: flex;
            flex-wrap: wrap;
        }
        nav .ong p{
            font-size: 17px;
            margin-right: 15px;
            cursor: pointer;

        }

         a 
        {
            text-decoration: none;
            color: #000;

        }
       
      .menu {
        background-color:#D98880;
         height: 40vw;
        width: 19.7vw;
        position: fixed;
        
        
      }


       .menu tr td{
        width: 200px;
        text-align: center; 
        vertical-align: center;
        font-weight: bold;
         cursor: pointer;
       
        border: none;
       }
       .menu_g {
        display: flex;
        background-color: #f2f2f2;

       }
    

       .Article 
       {
        
        width: 80vw;
        margin-left: 19.7vw;


       }
       .Article th{
        font-size: 20px;
        font-weight: bold;
        height: 50px;
        background-color: #EBE0E0;
       
       }
       .type_g,.type{
         display: flex;
       }
       
      p{
        margin-top: -0.5px;
        margin-right: 40px;
      }
      .Article td {
        font-size: 15px;
        padding: 20px;
        text-align: center;
        font-size: 20px;

      }
      .Article,tr,td
      {
        border: 1px solid #f2f2f2;
        border-collapse: collapse;
      }
      .Article .lab
      {
        font-weight: bold;
        color: gray;
        font-size: 15px;
      }
      .text{
        width: 50vw;
        height: 30px;
        text-align: left;
        background-color: #f2f2f2;
        border: none;
        outline: none;
      }
      .file{
        height: 30px;
        margin-right: 20px;

      }
      .submitb{
        border: none;
        width: 400px;
        height: 30px;
        cursor: pointer;
        font-size: 15px;
        background-color: #D98880;
        font-weight: bold;

      }


    </style>
</head>
<body style="margin: 0px; padding: 0px; font-family: sans-serif,Open Sans;">
    <nav>
        <h1>Boutique.net</h1>
        <div class="ong">
                <a href="profil.php"><p class="link" ><i class="fas fa-user"> Profil </i></p></a>
                <p class="link">
                    <a href="../connexion_BD/logout.php" style="color: black;">
                        <i class="fas fa-sign-out-alt"> Se déconnecter</i>
                    </a>
                </p>
        </div>    
    </nav>
  
     <div class="menu_g">
            <table class="menu">
              <tr>
                    <td><a href="./"><div class="menu_items">TABLEAU DE BORD</div></a></td>
                </tr>
                <tr>
                    <td><a href="Clients.php"><div class="menu_items">CLIENTS</div></a></td>
                </tr>
                <tr>
                    <td><a href="Articles.php"><div class="menu_items">ARTICLES</div></a></td>
                </tr>
                <tr>
                    <td><a href="Commandes.php"> <div class="menu_items">COMMANDES</div></a></td>
                </tr>
                    <td><a href="Commentaires.php"> <div class="menu_items">COMMANTAIRES</div></a></td>
                </tr>

            </table> 
            <form method="POST" action="AjouterArticle.php">
            <table class="Article" style="background-color: #fff;">
                <tr>
                    <th colspan="2">Ajouter Article</th>
                </tr>
                 <tr>  
                    <td class="lab">
                        <label>Designation de l'article*</label>
                    </td>
                    <td> 
                        <input type="text" class="text" name="desg" placeholder="Designation de l'article">
                    </td>
                <tr>
                    <td class="lab">
                    <label>Discription de l'article*</labe>
                    </td>
                    <td>
                    <input type="text" class="text" name="desc" placeholder="Discription de l'article"> 
                    </td>
                </tr>
                <tr>
                    <td class="lab">
                        <label>Type de l'article*</label>
                    </td>
                    <td>
                        <div class="type_g">
                        <div class="type"><input type="radio" name="type" checked value="1" class="radio"><p>Femmes</p></div>
                        <div class="type"><input type="radio" name="type" value="2" class="radio"><p>Hommes</p></div>  
                        <div class="type"><input type="radio" name="type" value="3" class="radio"><p>Enfants</p></div> 
                        </div>
                    </td>
                </tr>
                <tr>
                    <td class="lab">
                        <label>Couleur de l'article* </label>
                    </td>
                    <td>
                        <input type="text" class="text" name="couleur" placeholder="Couleur de l'article">
                    </td>
                </tr>
                 <tr>
                    <td class="lab">
                        <label>Taille de l'article* </label>
                    </td>
                    <td>
                        <input type="text" class="text" name="taille" placeholder="Taille de l'article">
                    </td>
                </tr>
                <tr>
                    <td class="lab">
                        <label>Prix de l'article*</label>
                    </td>
                    <td>
                        <input type="text" class="text" name="Prix" placeholder="Prix de l'article">
                    </td>
                </tr>
                <tr>
                    <td class="lab">
                        <label>Quantité en stock de l'article*</label>
                    </td>
                    <td>
                         <input type="text" class="text" name="QtStock" placeholder="Quantité en stock de l'article">
                    </td>
                </tr>
                <tr>
                    <td class="lab">
                        <label>Image principale de l'article*</label>
                    </td>
                    <td>
                        <input type="file" class="file" name="ImgP" >
                    </td>
                </tr>
                 <tr>
                    <td class="lab">
                        <label>Image secondaire de l'article*</label>
                    </td>
                    <td>
                        <input type="file" class="file" name="ImgS1" >
                    </td>
                </tr> 
                <tr>
                    <td class="lab">
                        <label>Image secondaire de l'article*</label>
                    </td>
                    <td>
                        <input type="file" class="file" name="ImgS2" >
                    </td>
                </tr>
                <tr>
                    <td colspan="2"><input type="submit" name="submit" class="submitb" value="Ajouter Article"></td>
                </tr>                                                              
            </table>
            </form>          
           
               
    </div>  
</body>
</html>
<?php
}
else {
    header("Location : ../index.php");
}

if(isset($_POST['submit']))
    {
       $desg=htmlentities(trim($_POST['desg']));
       $desc=htmlentities(trim($_POST['desc']));
       $type=htmlentities(trim($_POST['type']));
       $col=htmlentities(trim($_POST['couleur']));
       $taille=htmlentities(trim($_POST['taille']));
       $prix=htmlentities(trim($_POST['Prix']));
       $QtStock=htmlentities(trim($_POST['QtStock']));
       $ImgP=htmlentities(trim($_POST['ImgP']));
       $ImgS1=htmlentities(trim($_POST['ImgS1']));
       $ImgS2=htmlentities(trim($_POST['ImgS2']));

       $req="exec ps_Ajouter_Article_par_Admin '$type','$desg','$desc','$taille','$col','$prix',
            '$QtStock','$ImgP','$ImgS1','$ImgS2' ";
        $res=sqlsrv_query($conn,$req);

    }
       
        
 

?>
