<?php 
session_start();
include "connexion_BD/connexion.php";
include 'header.php';
include "panier.class.php";
$panier=new panier();

if(isset($_SESSION['id']))
{
	if(isset($_GET['erreur']))
		{
			echo '<script type="text/javascript">
				alert("Quntité Insuffisente");
				</script>';
	    }
	if(isset($_GET['del']))
		{
			$art=$_GET['del'];
			$utl=$_SESSION['id'];
			$req="exec ps_supprimer_Article_dans_panier '$utl','$art'";
			$res=sqlsrv_query($conn,$req);

			//$panier->del($_GET['del']);
		}
?>
<!DOCTYPE html>
<html>
<head>

	<meta charset="utf-8">
	<title>Panier</title>
	<style type="text/css">

		table {
			
			margin:50px;
		}
		table tr th{
			background-color: #f2f2f2;
			
		}
		h2 {
			margin-bottom: -80px;
			width: 200px;
			height: 75px;
			text-align: center;
		}
		table tr th {
			width: 200px;
			height: 75px;
			text-align: center;
			font-size: 20px;
		}

		table tr td {
			width: 200px;
			height: 75px;
			text-align: center;
		}
		table tr td img {
			width: 200px;
			height: 150px;
		}
		 table,
     	 th,
        td, tr {
        
        border: 1px solid #f2f2f2;
        border-collapse: collapse;
      }
      input{
      	text-align: center;
      	border: 1px solid #f2f2f2;
      	outline: none;
      }
      a {
      	border: none;
      	color: gray;
      	background-color: #fff;
      	cursor: pointer;

      }
      table tr .total {
      	text-align: right;
      	padding-right:40px ;
      	background-color: #f2f2f2 ;
      	
      }
      table tr td,table tr td input {
      	font-size: 20px;
      }
      .action {
      	margin-buttom: 50px;
      }
      .frais {
      	font-size: 15px;
      	color: gray;
      }
      .btn button a {
      	text-decoration: none;
      	background-color:#D98880 ;
      	color: black;

      }
       
      .btn {
      margin: 15px auto;
      width: 85vw;
      display: flex;
      justify-content: center;
      

      }
      .btn button {
      	width: 300X;
      	padding: 15px 25px;
      	margin-left: 50px;
      	text-align: center;
      	border-radius: 5px;
      	outline: none;
      	border: none;
      	padding: 15px 25px;
      	cursor: pointer;
      	background-color: #D98880 ;
      	font-size: 15px;
      	font-weight: bold;
      	margin: 15px auto;
      	

      }
      #Factures{
      	margin-left: -100px;
      } 
     
      }
	</style>
</head>
<body>
	<?php
	$idUtilisateur=$_SESSION['id'];
	$req="exec ps_panier_Utilisateur_Client '$idUtilisateur'";
	$params = array();
	$options =  array( "Scrollable" => SQLSRV_CURSOR_KEYSET );
	$res = sqlsrv_query($conn,$req,$params ,$options);
	$row_count = sqlsrv_num_rows( $res);

	//$res=sqlsrv_query($conn,$req);
	//$pan=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
	if($row_count>0)
	{
		echo '
			<h2>Voter Panier</h2>
			<table>
				<tr>
					<th>produit</th>
					<th>Qauntite Commandée</th>
					<th>Prix de produits</th>
					<th>Total</th>
					<th>Actions</th>
				</tr>
				';
				$Total=0;
			while ($pan=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC)) {
				echo '<tr>
						
						<td><img src="'.$pan['CheminImage'].'"></td>
						<td>
							'.$pan['QtCmd'].'

						</td>
						<td>'.number_format($pan['PrixArticle'],2,',',' ').' dh </td>
						<td>'.number_format($pan['PrixArticle']*$pan['QtCmd'],2,',',' ').
						' dh</td>
						<td>
							<div class="action">
							<a href="ajouterpanier.php?id='.$pan['IdArticle'].'"><i class="fas fa-plus"></i></a>
							</div>
							<div class="action">
							<a href="supprimerpanier.php?id='.$pan['IdArticle'].'"><i class="fas fa-minus"></i></a>
							</div>
							<div class="action">
							<a href="panier.php?del='.$pan['IdArticle'].'"><i class="fas fa-trash-alt"></i></a>
							</div>

						</td>
						</from>

					</tr>';
					$Total=$Total+$pan['PrixArticle']*$pan['QtCmd'];
					
				}	

			echo '<tr>
					<td colspan="5" class="total"><p>Total Géneral : <strong>'.number_format($Total,2,',',' ').' dh</strong></p>
					<p class="frais">Frais de livraison non inclus pour le moment</p>

					</td>
					</tr>

			</table>';

		}

	}
	
	?>	
	<div class="btn">
		<button >
			<a href="home.php">POURSUIVRE VOS ACHATS</a>
		</button>
		<button  id="Factures">
			<a href="Livraison.php"> FINALISER VOTRE COMMANDE</a>
		</button>
	</div>

	<?php
	include 'footer.php';
	?>

</body>
</html>
