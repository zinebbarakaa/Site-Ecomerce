<?php 
session_start();
include '../connexion_BD/connexion.php';
if(isset($_SESSION['id']) && isset($_GET['idfacture']) )
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
        position: fixed;
        width: 19.8vw;
        
      
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
    

       .Liv 
       {
        
        width: 80.2vw;
        height: 40vw;
        margin-left: 19.8vw;

       }
       .Liv th{
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
      .Liv td {
        font-size: 15px;
        padding: 20px;
        text-align: center;

      }
      .Liv,tr,td
      {
        border: 1px solid #f2f2f2;
        border-collapse: collapse;
      }
      .Liv .lab
      {
        font-weight: bold;
        color: gray;
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
 		<form method="POST" action="valider_Liv.php?idfacture=<?= $_GET['idfacture'];?>">
            <table class="Liv" style="background-color: #fff;">
            	<?php 
            	$fact=$_GET['idfacture'];
            	$req="exec ps_donnees_Laivraison '$fact'";
            	$res=sqlsrv_query($conn,$req);
            	$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
            	?>
                <tr>
                    <th colspan="2">Valider la livraison de la facture <?= $_GET['idfacture'] ?> </th>
                </tr>
                 <tr>  
                    <td class="lab">
                        <label>Ville de la livraison*</label>
                    </td>
                    <td> 
                        <input type="text" class="text" value="<?= $row['NomVille'] ?>">
                    </td>
                <tr>
                    <td class="lab">
                    <label>Adresse de l livraison*</labe>
                    </td>
                    <td>
                    <input type="textarea" class="text"  value="<?= $row['AdresseLiv'] ?>" > 
                    </td>
                </tr>
                
                <tr>
                    <td class="lab">
                        <label>Date de la livraison*</label>
                    </td>
                    <td>
                        <input type="date" class="text" name="date" >
                    </td>
                </tr>
                
                    
                <tr>
                    <td colspan="2"><input type="submit" name="submit" class="submitb" value="Valider la livraison "></td>
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

?>
