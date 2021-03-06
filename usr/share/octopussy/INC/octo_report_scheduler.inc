<%
my %arg = @_;

my $form = $arg{form};
my $url = $arg{url};
my $device = $arg{device};
my $service = $arg{service};
my @report_list = Octopussy::Report::List(undef, undef);
my @used_services = Octopussy::Service::List_Used();

if (scalar(@report_list) > 0)
{
%>
<AAT:Form action="./report_scheduler.asp">
<AAT:Box align="C">
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
	<AAT:BoxCol align="R"><AAT:Label value="_NAME" style="B" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Entry name="name" size="30" /></AAT:BoxCol>
	<AAT:BoxCol align="R"><AAT:Button name="report" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Label value="_REPORT" style="B" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Selector name="report" list=\@report_list /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="6"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol align="R"><AAT:Button name="device" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Label value="_DEVICE" style="B" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Inc file="octo_selector_device_and_devicegroup_dynamic"
		multiple="1" size="5" url="$url?device=" selected="$device" /></AAT:BoxCol>
	<AAT:BoxCol align="R"><AAT:Button name="service" /></AAT:BoxCol>
	<AAT:BoxCol><AAT:Label value="_SERVICE" style="B" /></AAT:BoxCol>
  <AAT:BoxCol>
	<AAT:Inc file="octo_selector_service_dynamic" 
		multiple="1" size="5" url="$url?device=$device&service=" 
    selected="$service" restricted_services=\@used_services />
	</AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol></AAT:BoxCol>
  <AAT:BoxCol align="R"><AAT:Label value="_LOG_LEVEL" style="B" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Inc file="octo_selector_loglevel" any="1" /></AAT:BoxCol>
  <AAT:BoxCol></AAT:BoxCol>
	<AAT:BoxCol align="R"><AAT:Label value="_TAXONOMY" style="B" /></AAT:BoxCol>
  <AAT:BoxCol><AAT:Inc file="octo_selector_taxonomy" any="1" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="6"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol rspan="2"></AAT:BoxCol>
	<AAT:BoxCol align="R" rspan="2">
	<AAT:Label value="_BEGIN" style="B" /></AAT:BoxCol>
	<AAT:BoxCol rspan="2">
	<AAT:Selector_Time name="start" step="5" selected="00/5" /></AAT:BoxCol>
	<AAT:BoxCol align="R" rspan="2">
	<AAT:Label value="_PERIOD" style="B" /></AAT:BoxCol>
	<AAT:BoxCol cspan="3">
	<AAT:Inc file="octo_selector_dayhour_relative" day_name="Day1" 
		hour_name="Hour1" selected="$day1" />
	</AAT:BoxCol>	
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol cspan="3">
	<AAT:Inc file="octo_selector_dayhour_relative" day_name="Day2"
    hour_name="Hour2" selected="$day2" />
  </AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="6"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol align="R">
	<AAT:Label value="_DAY_OF_WEEK" style="B" /></AAT:BoxCol>
	<AAT:BoxCol cspan="5"><AAT:CheckBox_DayOfWeek name="dow" />
	</AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol align="R">
  <AAT:Label value="_DAY_OF_MONTH" style="B" /></AAT:BoxCol>
  <AAT:BoxCol cspan="5"><AAT:CheckBox_DayOfMonth name="dom" />
	</AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol align="R"><AAT:Label value="_MONTH" style="B" /></AAT:BoxCol>
  <AAT:BoxCol cspan="5"><AAT:CheckBox_Month name="month" />
	</AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="6"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
	<AAT:BoxCol cspan="6"><AAT:Inc file="octo_export_mail" width="100%" />
	</AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol cspan="6"><AAT:Export_FTP width="100%" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol cspan="6"><AAT:Export_SCP width="100%" /></AAT:BoxCol>
</AAT:BoxRow>
<AAT:BoxRow><AAT:BoxCol cspan="6"><hr></AAT:BoxCol></AAT:BoxRow>
<AAT:BoxRow>
  <AAT:BoxCol align="C" cspan="6">
	<AAT:Form_Submit value="_SCHEDULE" /></AAT:BoxCol>
</AAT:BoxRow>
</AAT:Box>
</AAT:Form>
<%
}
else
{
	%><div align="center">
	<AAT:Label value="_MSG_NEED_REPORT_FOR_SCHEDULE" link="./reports.asp" /></div><%
}
%>
