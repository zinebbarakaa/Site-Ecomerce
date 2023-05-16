<?php
session_start();
include "connexion_BD/connexion.php";
include "panier.class.php";
if($_POST['submit'])
{
	if(isset($_SESSION['id']) && isset($_SESSION['nom']) && isset($_SESSION['prenom']) && isset($_SESSION['tel']) && isset($_POST['Adresse']) && $_POST['Ville'])
	{
		if(empty($_POST['Adresse']))
		{
			
 			header("Location: Livraison.php");
		}
		else 
		{
		

			$Adresse=htmlentities(trim($_POST['Adresse']));
			$Ville=htmlentities(trim($_POST['Ville']));
			$_SESSION['Ville']=$Ville;
			$_SESSION['Adresse']=$Adresse;

	


?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Paiment</title>
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<style type="text/css">
		body{
			background-color: #f2f2f2;
		}
		.livraison,.paiment{
			margin: 15px auto;
			width: 75vw;
			background-color:#fff ;
			border-radius: 10px;
			padding: 10px;
		}
		table {
			
			margin:15px auto;
			width: 70vw;
			margin-bottom: 10px;

		}
		table caption {
			padding: 10px;
			font-size: 20px;
		}
		table,tr {
        
        border: 1px solid  #f2f2f2;
        border-collapse: collapse;
    	}
    	table tr td  {
    		height: 75px;
    		padding-left: 20px;
    		margin: 10px;
    	}
    	table tr td p {
    		font-size: 15px;
    		

    	}
    	a{
    		text-decoration: none;
    		font-size: 18px;
    		font-weight: bold;
    		color: #D98880;

    	}
    	img {
    		width: 150px;
    		margin-bottom: -15px;
    		margin-right: 10px;
    	}
    	.mode_paiment {
    		margin-bottom: 20px;
    	}
    	.submitb {

			width: 65vw;
			height: 40px;
			font-size: 15px;
			font-weight: bold;
			border: none;
			text-align: center;
			color: #fff;
			cursor: pointer;
			background-color:#D98880  ;
		}
		.Montant_T div {
			width: -300px;
			text-align: right;
			font-weight: bold;
		}
		i{
			width: 20px;
		}
		.Montant {
			margin-bottom: 5px;
		}



	</style>
</head>
<body>
	
	<div class="livraison">
		<table>
			<caption>FINALISATION DE LA COMMANDE</caption>
			<tr>
				<td>
					<div style="font-size:20px;"><i class="fas fa-check-circle" style="color:#01D758;"></i> 1.Adresse de livraison </div>
				</td>
				<td>
					<a href="Livraison.php">MODIFIER</a>
				</td>
			</tr>
			<tr>
				<td colspan="2">
					<p style="font-weight: bold;"><?php echo $_SESSION['prenom'].'  '.$_SESSION['nom']; ?></p>
					<p><?php  echo $Adresse.','.$Ville; ?></p>
					<p>+212<?php echo $_SESSION['tel']; ?></p>
				   
				</td>
				
			</tr>
		</table>
		
	</div>
	<div class="paiment">
		<form action="Facture.php" method="POST" >
			<table>
				<tr>
					<td>
						<div style="font-size:20px;"><i class="fas fa-check-circle" style="color:#99A8A6;"></i> 2.Mode de paiment </div>
					</td>
				</tr>
				<tr>
					<td>

						Quel moyen de paiment voulez-vous utiliser?
					</td>
					
				</tr>
				<tr>
					<td colspan="2">
						
						<div class="mode_paiment">
							<input type="radio" name="Paiment" checked  value="PBank"><img src="IMAGES\pngegg.png"> Paiment par carte bancaire ( facile , sécurisé est permet d'éviter tout contact avec monnaie ou des billets )
							<p style="color:#99A8A6; margin-left: 20px;">
								Toutes vos transactions sont protégées et sécurisées à 100%.    
							</p>
						</div>
						<div class="mode_paiment">
							<input type="radio"  name="Paiment" value="PCash"><i class="fas fa-handshake">
							</i> Paiment cash à la livraison (favorisez le paiment par la carte bancaire )
							<p style="color:#99A8A6; margin-left: 20px;">
								Payez en espacès dès que vous recevez votre commande  
							</p>
						</div>
					</td>
				</tr>
				<tr>
					<td >
						<div class="Montant">
							Sous-Total
						</div>
						<div class="Montant">
							Frais de livraison
						</div>
						<div class="Montant">
							TOTAL
						</div>

					</td>
					<td class="Montant_T">
						<div class="Montant">
							<?php 
							$utl=$_SESSION['id'];
							$req="exec ps_Montant_Panier '$utl' ";
							$res=sqlsrv_query($conn,$req);
							$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
							$total=$row['Montant'];
							echo number_format($row['Montant'],2,',',' ').' dhs';

							?>
						</div>
						<div class="Montant">
							<?php 
							$req="exec ps_prix_Laivraison '$Ville' ";
							$res=sqlsrv_query($conn,$req);
							$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
							$total=$total+$row['PrixLiv'];
							echo number_format($row['PrixLiv'],2,',',' ').' dhs';
							?>	
						</div >

						<div class="Montant">
							<?=  number_format($total,2,',',' ').' dhs'; ?>
							
						</div>
					</td>
					
				</tr>
				
							<?php  
							if($total<=3000 && $total>=300)
							{
								echo '<tr>
										<td>		
											<div >
											Vous avez gagner une réduction de 5%
											</div>
											<div>
											Nouveau TOTAL:
											</div>
										</td>
								
										<td class="Montant_T" >
											<div>'.number_format(0.95*$total,2,',',' ').' dhs</div>
										<td>
									</tr>';
						
							}
						if($total>3000)
							{
								echo '<tr>
										<td >
											<div >
											<div>
											Vous avez gagner une réduction de 20%
											</div>
											<div>
											Nouveau TOTAL:
											</div>
										</td>
								
										<td class="Montant_T">
											<div>'.number_format(0.85*$total,2,',',' ').' dhs</div>
										<td>
									</tr>';						
							}	

						
					
					?>
				
				
				<tr>
					<td colspan="2">
						<input type="submit" name="submit" class="submitb" value="CONFIRMER LA COMMADE" ></a>
					</td>
				</tr>

			</table>
		</form>		
	</div>
<?php  include "footer.php" ?> 

</body>
</html>
<?php
}
}
}
else 
{
	header("Location :Livraison.php");
}