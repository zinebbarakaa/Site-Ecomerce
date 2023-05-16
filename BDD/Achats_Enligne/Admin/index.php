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
        width: 19.8vw;
        position: fixed;
        height: 40vw;
        
      
       }

       .menu tr td{
        text-align: center; 
        vertical-align: center;
        font-weight: bold;
         cursor: pointer;
       
        border: none;
       }
       .menu_g {
        display: flex;
        background-color: #f2f2f2;
         height: 38.4vw;

       }
       .statistique {
       
        width: 80.2vw;
        margin-top: -20px;
        height: 38.4vw;
        margin-left: 19.8vw;
       
       }
       .statistique th {
        height: 100px;
        background-color: #EBE0E0;

       }
       .statistique tr td {
        width: 40.1vw;
        background-color: #f2f2f2;

       }
        .statistique tr td .items {
            height: 100px;
            width: 35vw;
            background-color: #fff;
            padding: 15px;
            vertical-align: center;
            margin-top: 10px;
            margin-left: 10px;
            display: flex;
            justify-content: space-between;
            font-size: 20px;
            color: #524C4C;
            
        }
         .statistique tr td .items i {
            margin-top: 20px;
            margin-right: 30px;
            

         }
         .statistique tr td .items p{
            margin-left: 30px;

         }

         .statistique tr th p {
            text-align: left;
            margin-left: 30px;
            font-size: 30px;
            margin-bottom: 15px;
            font-weight: ;
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
                 <tr>
                    <td><a href="Commentaires.php"> <div class="menu_items">COMMANTAIRES</div></a>  </td>
                </tr>

            </table>           
            <table class="statistique">
                    <tr>
                        <th colspan="2">
                            <p>Tableau de bord de l'admin</p> 
                        </th>
                    </tr>
                    <tr>
                        <td>
                            <div class="items">
                                <div>
                                    <p style="font-weight:bold;">Nombre Clients</p>
                                    <p><?php 
                                    $req="exec ps_Nombe_Clients";
                                    $res=sqlsrv_query($conn,$req);
                                    $row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
                                    echo $row['nbrClients'];
                                    ?> </p>
                                </div>
                                <div><i class="fas fa-user"></i>
                                </div>
                                
                            </div>
                        </td>
                        <td>
                             <div class="items">
                                <div>
                                    <p style="font-weight:bold;">Nombre Produits</p>
                                    <p><?php 
                                    $req="exec ps_Nombe_Articles";
                                    $res=sqlsrv_query($conn,$req);
                                    $row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
                                    echo $row['nbrArticles'];
                                    ?>  </p>
                                </div>
                                <div><i class="fas fa-tshirt"></i>
                                </div>
                                
                            </div>
                        </td>
                    </tr>
                     <tr>
                        <td>
                             <div class="items">
                                <div>
                                    <p style="font-weight:bold;">Nombre Commandes</p>
                                    <p><?php 
                                    $req="exec ps_Nombe_Commandes_Factures";
                                    $res=sqlsrv_query($conn,$req);
                                    $row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
                                    echo $row['NCommandes'];
                                    ?></p>
                                </div>
                                <div><i class="fas fa-shopping-bag"></i>
                                </div>
                                
                            </div>
                        </td>
                        <td>
                             <div class="items">
                                <div>
                                    <p style="font-weight:bold;">Nombre Commantaires</p>
                                    <p><?php 
                                    $req="exec ps_Nombre_Commentaire";
                                    $res=sqlsrv_query($conn,$req);
                                    $row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
                                    echo $row['NbrComment'];
                                    ?></p>
                                </div>
                                <div><i class="fas fa-edit"></i>
                                </div>  
                            </div>
                        </td>
                    </tr>
             </table>
               
    </div>
          
</body>
</html>
<?php
}
else {
    header("Location : ../index.php");
}

?>